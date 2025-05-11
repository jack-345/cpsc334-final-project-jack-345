#include "rivers.h"

int main()
{
    Tree tree;

    std::vector<std::string> top_level_options = {"Print Overview", "Navigate", "Exit"};
    int choice = get_user_option(top_level_options);

    while (choice != 2)
    {
        if (choice == 0)
        {
            tree.print(std::cout);
        }
        else
        {
            if (navigate_tree(tree))
            {
                break;
            }
        }

        choice = get_user_option(top_level_options);
    }

    return 0;
}