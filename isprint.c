

int isprint(int c)
{
	if (c >= ' ' && c != 177)
		return (1);
	else
		return (0);
}
