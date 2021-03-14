void postfix(void)
{
	/* ������ ���� ǥ������� ����Ѵ�. ���� ���ڿ�, ����, top�� �������̴�. */
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;	/* eos�� ���ÿ� ���´�. */
	stack[0] = eos;
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen) {
			/* ���� ��ȣ�� ���� ������ ��ū���� �����ؼ� ��½�Ŵ */
			while (stack[top] != lparen)
				print_token(delete(&top));
			delete(&top);		/* �°�ȣ�� ������. */
		}	
		else {
			/* symbol�� isp�� token�� icp���� ũ�ų� ������symbol��
				�����ϰ� ��½�Ŵ */
			while (isp[stack[top]] >= icp[token])
				print_token(delete(&top));
			add(&top, token);
		}
	}
	while ((token = delete(&top)) != eos)
		print_token(token);
	printf("\n");
}

