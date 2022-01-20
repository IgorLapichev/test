#pragma once

#include "Utils.h"


class BaseComparator;

class TestManager
{
public:
    TestManager() = delete;
    TestManager(std::shared_ptr<BaseComparator> comporator);

    std::list <std::pair<std::wstring, std::wstring>> compareFolders();

private:
    std::shared_ptr<BaseComparator> m_comporator = nullptr;
    Utils m_utils;
    std::wstring m_firstPath, m_secondPath;
};