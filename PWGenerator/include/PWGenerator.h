#ifndef PWGENERATOR_H_
#define PWGENERATOR_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/random.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool is_num(char *str);
bool is_error(int ac, char **av);
int pwgenerator(char **av);

#endif /* !PWGENERATOR_H_ */
