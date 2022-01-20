#include "TestManager.h"

#include "Comparator.h"
#include <iostream>

TestManager::TestManager(std::shared_ptr<BaseComparator> comporator)
{
    m_comporator = comporator;

    m_firstPath = m_utils.getPath();
    m_secondPath = m_utils.getPath();
}

std::list <std::pair<std::wstring, std::wstring>> TestManager::compareFolders()
{
    std::list <std::pair<std::wstring, std::wstring>> resultPairs;

    try
    {
        if (m_comporator == nullptr)
            throw "Comparator is not set";

        for (auto const& first_entry : std::filesystem::directory_iterator{ m_firstPath })
        {
            if (m_utils.isFileExists(first_entry))
            {
                for (auto const& second_entry : std::filesystem::directory_iterator{ m_secondPath })
                {
                    if (m_utils.isFileExists(second_entry))
                    {
                        if (first_entry.file_size() == second_entry.file_size())
                        {
                            if (m_comporator->compareFiles(first_entry.path(), second_entry.path()))
                                resultPairs.push_back(std::pair(first_entry.path(), second_entry.path()));
                        }
                    }
                    else
                        std::wcerr << std::wstring(L"Can not find file: ") + second_entry.path().wstring() << std::endl;
                }
            }
            else
                std::wcerr << std::wstring(L"Can not find file: ") + first_entry.path().wstring() << std::endl;
        }
    }
    catch (std::exception e)
    {
        throw;
    }

    return resultPairs;
}