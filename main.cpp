#include "FileCopierApp.h"

using net::draconia::FileCopierApp;

int main(int argc, char *argv[])
{
    FileCopierApp a(argc, argv);

    return(a.exec());
}
