
#include <stdio.h>
#include <string.h>
#include "main.h"
#include <limits.h>
#include <ctype.h>

void testfunction(void *content)
{
	char buffer[] = "modified";
	char *holder = (char *) content;

	for (int i = 0; i < 9; i++) {
		holder[i] = buffer[i];
	}
}

/*
 * 1  - memset
 * 2  - memcpy
 * 4  - memmove
 * 8  - strchr
 * 16 - toupper
 */

size_t set_bits(int argc, char **argv)
{
	size_t bits;
	int i;

	bits = 0;
	i = 0;
	while (i < argc)
	{
		if (!strcmp(argv[i], "memset"))
			bits = bits | 1;
		else if (!strcmp(argv[i], "memcpy"))
			bits = bits | 2;
		else if (!strcmp(argv[i], "memmove"))
			bits = bits | 4;
		else if (!strcmp(argv[i], "strchr"))
			bits = bits | 8;
		else if (!strcmp(argv[i], "toupper"))
			bits = bits | 16;
		else if (!strcmp(argv[i], "tolower"))
			bits = bits | 32;
		else if (!strcmp(argv[i], "strrchr"))
			bits = bits | 64;
		else if (!strcmp(argv[i], "memchr"))
			bits = bits | 128;
		else if (!strcmp(argv[i], "calloc"))
			bits = bits | 256;
		else if (!strcmp(argv[i], "substr"))
			bits = bits | 512;
		else if (!strcmp(argv[i], "strjoin"))
			bits = bits | 1024;
		else if (!strcmp(argv[i], "strtrim"))
			bits = bits | 2048;
		else if (!strcmp(argv[i], "itoa"))
			bits = bits | 4096;
		else if (!strcmp(argv[i], "ft_lstnew"))
			bits = bits | 8192;
		else if (!strcmp(argv[i], "lstadd_front"))
			bits = bits | 16384;
		else if (!strcmp(argv[i], "lstdelone"))
			bits = bits | 32768;
		else if (!strcmp(argv[i], "lstlast"))
			bits = bits | 65536;
		else if (!strcmp(argv[i], "mandatory"))
			bits = bits | 8191; // 0b1111111111111
		else if (!strcmp(argv[i], "bonus"))
			bits = bits | 122880; // 0b11110000000000000
		i++;
	}
	return (bits);
}

int main(int argc, char **argv)
{
	size_t bits;

	bits = set_bits(argc, argv);
	if (bits & 1) // memset
	{
		char buffer[10];
		char buffer2[10];

		void *eret = memset(buffer, '0', 10);
		void *gret = ft_memset(buffer, '0', 10);
		ft_memset(buffer2, '0', 10);
		puts("-> memset\n");

		int passed = 1;
		if (eret != gret) {
			printf("\t [!] wrong return value, expected %p, got %p\n", eret, gret);
			passed = 0;
		}
		if (strncmp(buffer, buffer2, 10)) {
			printf("\t [!] expected %s, got %s\n", buffer, buffer2);
			passed = 0;
		}
		memset(buffer, '0', 5);
		ft_memset(buffer2, '0', 5);
		if (strncmp(buffer, buffer2, 10)) {
			printf("\t [!] expected %s, got %s\n", buffer, buffer2);
			passed = 0;
		}
		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 2) // memcpy
	{
		char buffer[100] = "hello world";
		char buffer2[100];
		char buffer3[100];

		puts("-> memcpy\n");

		// setting memory to zero
		bzero(buffer2, 100);
		bzero(buffer3, 100);

		memcpy(buffer2, buffer, 10);
		ft_memcpy(buffer3, buffer, 10);

		int passed = 1;
		if (strncmp(buffer2, buffer3, 100))
		{
			printf("\t[!] expected %s, got %s\n", buffer2, buffer3);
			passed = 0;
		}

		memcpy(buffer, buffer2, 50);
		ft_memcpy(buffer, buffer3, 50);
		if (strncmp(buffer2, buffer3, 100))
		{
			printf("\t[!] expected %s, got %s\n", buffer2, buffer3);
			passed = 0;
		}

		memcpy(buffer, buffer2, 100);
		ft_memcpy(buffer, buffer3, 100);
		if (strncmp(buffer2, buffer3, 100))
		{
			printf("\t[!] expected %s, got %s\n", buffer2, buffer3);
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 4) // memmove
	{
		char buffer[20] = "hello world";
		char buffer2[20] = "hello world";
		char showcase[20] = "hello world";
		int passed = 1;

		puts("-> memmove\n");
		memmove(buffer, &buffer[5], 10);
		void *grut = ft_memmove(buffer2, &buffer2[5], 10);

		if (grut != buffer2)
		{
			printf("\t[!] wrong return value, expected %p, got %p\n", buffer2, grut);
			passed = 0;
		}

		if (strncmp(buffer, buffer2, 20))
		{
			print_array(showcase, 20);
			printf("\t[!] functionality error, expected:\n");
			print_array(buffer, 20);
			printf("\tgot:\n");
			print_array(buffer2, 20);
			passed = 0;
		}
		memmove(&buffer[5], buffer, 10);
		ft_memmove(&buffer2[5], buffer2, 10);

		if (strncmp(buffer, buffer2, 20))
		{
			printf("\t[!] functionality error, expected:\n");
			print_array(buffer, 20);
			printf("\tgot:\n");
			print_array(buffer2, 20);
			passed = 0;
		}

		// testing edge cases

		char *larg = malloc(sizeof(char) * 2000);
		char *change = &larg[50];
		char *larg2 = malloc(sizeof(char) * 2000);
		char *change2 = &larg2[50];

		memmove(larg, change, 1050);
		ft_memmove(larg2, change2, 1050);

		if (strncmp(change, change2, 1050))
		{
			printf("\t[!] memmoving large number (n = 1050)\n");
			passed = 0;
		}
		free(larg);
		free(larg2);

		if (passed)
			puts("\tall tests have passed!\n");

	}

	if (bits & 8) // strchr
	{
		char buffer[] = "hello world";
		int passed = 1;

		puts("-> strchr\n");
		if (strchr(buffer, 'h') != ft_strchr(buffer, 'h'))
		{
			printf("\t[!] expected %s, got %s\n", strchr(buffer, 'h'), ft_strchr(buffer, 'h'));
			passed = 0;
		}
		if (strchr(buffer, 'a') != ft_strchr(buffer, 'a'))
		{
			printf("\t[!] expected %s, got %s\n", strchr(buffer, 'h'), ft_strchr(buffer, 'h'));
			passed = 0;
		}
		if (strchr(buffer, ' ') != ft_strchr(buffer, ' '))
		{
			printf("\t[!] expected %s, got %s\n", strchr(buffer, 'h'), ft_strchr(buffer, 'h'));
			passed = 0;
		}
		if (strchr(buffer, '\0') != ft_strchr(buffer, '\0'))
		{
			printf("\t[!] expected %s, got %s\n", strchr(buffer, 'h'), ft_strchr(buffer, 'h'));
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}

	if (bits & 16) // toupper
	{
		int passed = 1;

		puts("-> toupper\n");
		if (ft_toupper(38) != toupper(38))
		{
			printf("\t[!] expected %d, got %d\n", toupper(38), ft_toupper(38));
			passed = 0;
		}
		if (ft_toupper(100) != toupper(100))
		{
			printf("\t[!] expected %d, got %d\n", toupper(100), ft_toupper(100));
			passed = 0;
		}
		if (ft_toupper('a') != toupper('a'))
		{
			printf("\t[!] expected %d, got %d\n", toupper('a'), ft_toupper('a'));
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 32) // toupper
	{
		int passed = 1;

		puts("-> tolower\n");
		if (ft_tolower(38) != tolower(38))
		{
			printf("\t[!] expected %d, got %d\n", tolower(38), ft_tolower(38));
			passed = 0;
		}
		if (ft_tolower(100) != tolower(100))
		{
			printf("\t[!] expected %d, got %d\n", tolower(100), ft_tolower(100));
			passed = 0;
		}
		if (ft_tolower('A') != tolower('A'))
		{
			printf("\t[!] expected %d, got %d\n", tolower('a'), ft_tolower('a'));
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 64) // strrchr
	{
		char buffer[] = "abcdefghijklmnopqrstvwxyzbc";
		int passed = 1;

		puts("-> strrchr\n");
		if (strrchr(buffer, 'b') != ft_strrchr(buffer, 'b'))
		{
			printf("\t[!] expected %s got %s\n", strrchr(buffer, 'b'), ft_strrchr(buffer, 'b'));
			passed = 0;
		}
		if (strrchr(buffer, 'c') != ft_strrchr(buffer, 'c'))
		{
			printf("\t[!] expected %s got %s\n", strrchr(buffer, 'c'), ft_strrchr(buffer, 'c'));
			passed = 0;
		}
		if (strrchr(buffer, '\0') != ft_strrchr(buffer, '\0'))
		{
			printf("\t[!] expected %p got %p\n", strrchr(buffer, '\0'), ft_strrchr(buffer, '\0'));
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 128) // memchr
	{
		int passed = 1;
		char buffer[] = "abcdefghijklmnopqrstvwxyzbc";

		puts("-> memchr\n");
		if (memchr(&passed, 'b', 10) != ft_memchr(&passed, 'b', 10))
		{
			printf("\t[!] expected %p got %p\n", memchr(&passed, 'b', 10), ft_memchr(&passed, 'b', 10));
			passed = 0;
		}

		if (memchr(&passed, 'c', 10) != ft_memchr(&passed, 'c', 10))
		{
			printf("\t[!] expected %p got %p\n", memchr(&passed, 'c', 10), ft_memchr(&passed, 'c', 10));
			passed = 0;
		}

		if (memchr(buffer, 'c', 10) != ft_memchr(buffer, 'c', 10))
		{
			printf("\t[!] expected %p got %p\n", memchr(buffer, 'c', 10), ft_memchr(buffer, 'c', 10));
			passed = 0;
		}
		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 256) // calloc
	{
		void *buffer = ft_calloc(20, 10);
		void *buffer2 = calloc(20, 10);
		int passed = 1;

		puts("-> calloc\n");
		if (memcmp(buffer, buffer2, 200) && buffer && buffer2)
		{
			printf("\t[!] wrong memory size and memory content\n");
			passed = 0;
		}
		free(buffer);
		free(buffer2);

		buffer = ft_calloc(100, 100);
		buffer2 = calloc(100, 100);
		if (memcmp(buffer, buffer2, 100 * 100) && buffer && buffer2)
		{
			printf("\t[!] wrong memory size and memory content\n");
			passed = 0;
		}
		free(buffer);
		free(buffer2);

		buffer = ft_calloc(100, ULONG_MAX / 3);
		// buffer2 = calloc(100, ULONG_MAX / 3);
		if (buffer != NULL)
		{
			printf("\t[!] overflow is not handled\n");
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 512) // substr
	{
		char *buffer;
		int passed = 1;

		puts("-> substr\n");

		buffer = ft_substr("hello world", 6, 5);
		if (strncmp("world", buffer, 5))
		{
			printf("\t[!] expected 'world' got '%s'\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_substr("hello world", 5, 0);
		if (buffer != NULL)
		{
			printf("\t[!] expected nil got %s\n", buffer);
			passed = 0;
			free(buffer);
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 1024) // strjoin
	{
		int passed = 1;
		char *buffer;

		puts("-> strjoin\n");
		buffer = ft_strjoin("hello ", "world");
		if (strcmp(buffer, "hello world"))
		{
			printf("\t[!] expected 'hello world', got '%s'\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_strjoin("hello", "");
		if (strcmp(buffer, "hello"))
		{
			printf("\t[!] expected 'hello', got '%s'\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_strjoin("", "");
		if (strcmp(buffer, ""))
		{
			printf("\t[!] expected '', got '%s'\n", buffer);
			passed = 0;
		}
		free(buffer);

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 2048) // strtrim
	{
		int passed = 1;
		char *buffer;

		puts("-> strtrim\n");

		buffer = ft_strtrim(" hello world ", " ");
		if (strcmp("hello world", buffer))
		{
			printf("\t[!] expected 'hello world', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_strtrim(" hello world ", " h");
		if (strcmp("ello world", buffer))
		{
			printf("\t[!] expected 'ello world', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_strtrim("", " ");
		if (strcmp("", buffer))
		{
			printf("\t[!] expected '', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 4096) // itoa
	{
		int passed = 1;
		char *buffer;

		puts("-> itoa\n");

		buffer = ft_itoa(1);
		if (strcmp("1", buffer))
		{
			printf("\t[!] expected '1', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_itoa(0);
		if (strcmp("0", buffer))
		{
			printf("\t[!] expected '0', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		buffer = ft_itoa(-9);
		if (strcmp("-9", buffer))
		{
			printf("\t[!] expected '-9', got %s\n", buffer);
			passed = 0;
		}
		free(buffer);

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 8192) // lstnew
	{
		int passed = 1;
		char *content = "hello world";
		t_list *lst;

		puts("-> lstnew\n");
		lst = ft_lstnew(content);
		if (lst != NULL && lst->content != content)
		{
			printf("\texpected content: %s, got %s\n", content, (char *) lst->content);
			passed = 0;
		}

		if (lst != NULL && lst->next != NULL)
		{
			printf("\texpected next: %s, got %s\n", content, (char *) lst->content);
			passed = 0;
		}
		free(lst);
		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 16384) // lstadd_front
	{
		int passed = 1;
		t_list *head = NULL;
		char *content = "hello";
		t_list *new1;
		t_list *new2;

		puts("-> lstadd_front\n");
		new1 = ft_lstnew(content);
		ft_lstadd_front(&head, new1);
		if (head != new1 || (new1 != NULL && new1->next != NULL))
		{
			printf("\tfailed adding first element to list\n");
			passed = 0;
		}
		new2 = ft_lstnew(content);
		ft_lstadd_front(&head, new2);
		if (head != new2 || (new2 != NULL && new2->next != new1))
		{
			printf("\tfailed adding second element to list\n");
			passed = 0;
		}
		ft_lstadd_back(&head, NULL);
		if (head != new2 || (new2 != NULL && new2->next != new1))
		{
			printf("\tpassing new = NULL changes the list\n");
			passed = 0;
		}
		free(new2);
		free(new1);
		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 32768) // lstdelone
	{
		int passed = 1;
		char content[] = "hello world";
		t_list *lst;

		puts("-> lstadd_front (leaks are not checked)\n");

		lst = ft_lstnew(content);
		ft_lstdelone(lst, &testfunction);
		if (strcmp(content, "modified") != 0)
		{
			printf("\tcontent has not been modified\n");
			passed = 0;
		}

		if (passed)
			puts("\tall tests have passed!\n");
	}
	if (bits & 65536) // lstlast
	{
		int passed = 1;
		char *content = "hello world";
		t_list *new;
		t_list *new2;

		puts("-> lstadd_front\n");
		new = ft_lstnew(content);
		new2 = ft_lstnew(content);

		if (ft_lstlast(new) != new)
		{
			printf("\texpected %p got %p", new, ft_lstlast(new));
			passed = 0;
		}
		new->next = new2;
		if (ft_lstlast(new) != new2)
		{
			printf("\texpected %p got %p", new2, ft_lstlast(new));
			passed = 0;
		}
		if (ft_lstlast(NULL) != NULL)
		{
			printf("\texpected NULL got %p", ft_lstlast(NULL));
		}
		free(new);
		free(new2);

		if (passed)
			puts("\tall tests have passed!\n");
	}

	return (0);
}
