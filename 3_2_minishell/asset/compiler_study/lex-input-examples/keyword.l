%{
	/* keyword */
%}
%%
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> keyword\n��, yytext); }
. ; //skip
%%
main()
{
	yylex();
}