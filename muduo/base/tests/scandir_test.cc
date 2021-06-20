#include <gtest/gtest.h>
#include <iostream>

#ifndef  _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int taskDirFilter(const struct dirent* d)
  {
    if (::isdigit(d->d_name[0])) {
      std::cout << (atoi(d->d_name)) << std::endl;
    }
    return 0;
  }

TEST(testName, testNum)
{

    struct dirent** namelist;
    int n;

    n = scandir("/proc/self/fd", &namelist, taskDirFilter, alphasort);
    if (n == -1) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    std::cout << "n is " << n << std::endl;
    while (n--) {
        /* printf("%s\n", namelist[n]->d_name); */
        free(namelist[n]);
    }
    free(namelist);

}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

