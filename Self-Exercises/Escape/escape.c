void escape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != '\n' && s[i] != '\t') {
			t[j]=s[i];
			j++;
		}
		else {
			t[j] = '\\';
			if (s[i] == '\n') t[j+1] = 'n';
			else t[j+1] = 't';
			j += 2;
		}
	}
}

void revert(char s[], char t[]) 
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; j++)
	{
		if (s[i] == '\\') {
			if (s[i+1] == 'n') t[j] = '\n';
			else t[j] = '\t';
			i+=2;
		}
		else {
			t[j] = s[i];
			i+=1
		}
	}
}