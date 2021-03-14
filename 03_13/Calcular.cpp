void postfix(void)
{
	/* 수식을 후위 표기식으로 출력한다. 수식 문자열, 스택, top은 전역적이다. */
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;	/* eos를 스택에 놓는다. */
	stack[0] = eos;
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen) {
			/* 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴 */
			while (stack[top] != lparen)
				print_token(delete(&top));
			delete(&top);		/* 좌괄호를 버린다. */
		}	
		else {
			/* symbol의 isp가 token의 icp보다 크거나 같으면symbol을
				제거하고 출력시킴 */
			while (isp[stack[top]] >= icp[token])
				print_token(delete(&top));
			add(&top, token);
		}
	}
	while ((token = delete(&top)) != eos)
		print_token(token);
	printf("\n");
}

