#pragma once

#include "targetver.h"

#include <iostream>
#include <string>
#include <tuple>
#include <stack>
#include <sstream>
#include <cmath>

#include "Calculator.h"
#include "stdafx.h"

template <class T>
constexpr auto ToUType(T enumerator) noexcept
{
    return static_cast<std::underlying_type_t<T>>(enumerator);
}

class Calculator
{
private:
    enum class Symbol : char
    {
        None = 0,
        LeftParenthesis = '(', RightParenthesis = ')',
        Plus = '+', Minus = '-',
        Multiply = '*', Divide = '/',
        Square = '^',
        Space = ' ',
    };

    static const std::string kNumbers;
    static const std::string kSymbols;
    static const std::string kSpecialSymbol;

    static std::stack<char> m_stack;

private:
    static const size_t GetPriority(char cipher);

public:
    Calculator() = delete;

    static const std::tuple<bool, std::string> InfixToPostfix(const std::string& infix);
    static const std::tuple<bool, double, std::string> Calculate(const std::string& equation);
};


#include "stdafx.h"

const std::string Calculator::kNumbers = "1234567890.";
const std::string Calculator::kSymbols = "()+-*/^";
const std::string Calculator::kSpecialSymbol = "+-";

std::stack<char> Calculator::m_stack;

const size_t Calculator::GetPriority(char cipher)
{
    int priority = 0;
    const Symbol symbol = static_cast<const Symbol>(cipher);

    switch (symbol)
    {
    case Symbol::Square:
        priority = 0;
        break;

    case Symbol::Multiply:
    case Symbol::Divide:
        priority = 1;
        break;

    case Symbol::Plus:
    case Symbol::Minus:
        priority = 2;
        break;

    case Symbol::LeftParenthesis:
        priority = 3;
        break;

    default:
        break;
    }

    return priority;
}

const std::tuple<bool, std::string> Calculator::InfixToPostfix(const std::string& infix)
{
    std::stack<char> stack;
    std::string         postfix;
    char chiper;

    for (int i = 0; i < infix.length(); i++)
    {
        chiper = infix[i];

        if (kNumbers.find(chiper) != std::string::npos)
        {
            postfix += chiper;
            continue;
        }
        else if (kSpecialSymbol.find(chiper) != std::string::npos)
        {
            if ((i == 0) ||
                ((kSymbols.find(infix[i - 1]) != std::string::npos) &&
                    (kNumbers.find(infix[i + 1]) != std::string::npos)))
            {
                postfix += chiper;
                continue;
            }
        }
        else if (kSymbols.find(chiper) == std::string::npos)
            return std::make_tuple(false, std::string("식이 잘못됐습니다."));

        if (chiper == ToUType(Symbol::LeftParenthesis))
            m_stack.emplace(chiper);
        else if (chiper == ToUType(Symbol::RightParenthesis))
        {
            while (!m_stack.empty() && (m_stack.top() != ToUType(Symbol::LeftParenthesis)))
            {
                postfix += ToUType(Symbol::Space);
                postfix += m_stack.top();
                m_stack.pop();
            }

            if (m_stack.empty())
                return std::make_tuple(false, std::string("식이 잘못됐습니다."));
            else
                m_stack.pop();
        }
        else
        {
            postfix += ToUType(Symbol::Space);
            while (!m_stack.empty() && (GetPriority(m_stack.top()) <= GetPriority(chiper)))
            {
                postfix += m_stack.top();
                postfix += ToUType(Symbol::Space);
                m_stack.pop();
            }
            m_stack.emplace(chiper);
        }
    }

    while (!m_stack.empty())
    {
        if (m_stack.top() == ToUType(Symbol::LeftParenthesis))
            return std::make_tuple(false, "식이 잘못됐습니다.");
        else
        {
            postfix += ToUType(Symbol::Space);
            postfix += m_stack.top();
            m_stack.pop();
        }
    }

    return std::make_tuple(true, postfix);
}

const std::tuple<bool, double, std::string> Calculator::Calculate(const std::string& equation)
{
    auto inToPostResult = InfixToPostfix(equation);
    if (!std::get<0>(inToPostResult))
        return std::make_tuple(std::get<0>(inToPostResult), 0, std::get<1>(inToPostResult));

    std::stack<double> stack;
    std::string chiper = "";
    std::stringstream equationStream(std::get<1>(inToPostResult));
    std::stringstream numberStream;

    double tempNum = 0;
    double rNum = 0;
    double lNum = 0;

    while (!equationStream.eof())
    {
        equationStream >> chiper;
        if (kSymbols.find(chiper) == std::string::npos)
        {
            numberStream.str(chiper);
            numberStream.clear();
            numberStream >> tempNum;
            stack.emplace(tempNum);
        }
        else
        {
            if (stack.size() < 2)
                return std::make_tuple(false, 0, std::string("식이 잘못됐습니다."));

            rNum = stack.top();
            stack.pop();
            lNum = stack.top();
            stack.pop();

            Symbol symbol = static_cast<const Symbol>(chiper[0]);
            switch (symbol)
            {
            case Symbol::Plus:
                stack.emplace(lNum + rNum);
                break;

            case Symbol::Minus:
                stack.emplace(lNum - rNum);
                break;

            case Symbol::Multiply:
                stack.emplace(lNum * rNum);
                break;

            case Symbol::Divide:
                stack.emplace(lNum / rNum);
                break;

            case Symbol::Square:
                stack.emplace(pow(lNum, rNum));
                break;

            default:
                break;
            }
        }
    }

    return std::make_tuple(true, stack.top(), std::string());
}

int main()
{
    while (true)
    {
        std::string infix = "";

        std::cout << "수식을 입력해주세요 : ";
        std::cin >> infix;

        auto resultTuple = Calculator::Calculate(infix);
        if (std::get<0>(resultTuple))
        {
            double        result = std::move(std::get<1>(resultTuple));
            std::string postfix = std::move(std::get<1>(Calculator::InfixToPostfix(infix)));

            std::cout << "Infix : " << infix << std::endl;
            std::cout << "Postfix : " << postfix << std::endl;
            std::cout << "Result : " << result << std::endl << std::endl;
        }
        else
            std::cout << std::get<2>(resultTuple) << std::endl << std::endl;
    }
    return 0;
}
