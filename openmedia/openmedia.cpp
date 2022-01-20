#include "TestManager.h"
#include "ComparatorFactory.h"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::wcerr << L"Enter comparison method.\n -b binary\n -h hash" << std::endl;
        return -1;
    }

    try
    {
        ComparatorFactory factory;
        auto comporator = factory.getComparator(argv[1]);

        TestManager manager(comporator);
        auto pairs = manager.compareFolders();

        std::wcout << std::endl << L"Search results:" << std::endl << std::endl;
        if (pairs.size() > 0)
        {

            for (auto& pair : pairs)
            {
                std::wcout << L"First  Folder: " << pair.first  << std::endl;
                std::wcout << L"Second Folder: " << pair.second << std::endl << std::endl;
            }
        }
    }
    catch (std::exception e)
    {
        std::wcout << e.what() << std::endl;
    }

    return 0;
}
