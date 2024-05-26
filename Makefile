list: 
	clang -c main_list.c -o main.o -Wall -Wextra -Werror -fsanitize=address,undefined -g
	clang -c lib/stack_list.c -o lib.o -Wall -Wextra -Werror -fsanitize=address,undefined -g 
	clang main.o lib.o -o bin -Wall -Wextra -Werror -fsanitize=address,undefined -g -lreadline

vector:
	clang -c main_vector.c -o main.o -Wall -Wextra -Werror -fsanitize=address,undefined -g
	clang -c lib/stack_vector.c -o lib.o -Wall -Wextra -Werror -fsanitize=address,undefined -g 
	clang main.o lib.o -o bin -Wall -Wextra -Werror -fsanitize=address,undefined -g -lreadline
