#include "rivers.h"
#include <sstream>

void assert(bool condition, const std::string &message)
{
    if (!condition)
    {
        std::cerr << message << std::endl;
        exit(1);
    }
}

int main()
{
    Tree tree;

    // Reset the tree since the constructor already inserts nodes
    tree.reset();

    // Tree insert tests

    RiverNode *river1 = new RiverNode();
    river1->name = "Foo River";
    river1->length = 100;

    tree.insert(nullptr, river1, true);

    assert(tree.getRoot() == river1, "Root is not river1");

    LakeNode *lake = new LakeNode();
    lake->name = "Bar Lake";
    lake->area = 200;

    tree.insert(river1, lake, false);

    assert(river1->right == lake, "River1's right is not Bar lake");

    DamNode *dam = new DamNode();
    dam->name = "Baz Dam";
    dam->height = 50;

    tree.insert(river1, dam, true);

    assert(river1->left == dam, "River1's left is not Baz Dam");

    RiverNode *badRiver = new RiverNode();
    badRiver->name = "Bad River";
    badRiver->length = 300;

    try
    {
        tree.insert(river1, badRiver, true);
        assert(false, "Inserting a node with a parent that already has a left child should throw an exception.");
    }
    catch (const std::invalid_argument &e)
    {
        assert(true, "Inserting a node with a parent that already has a left child should throw an exception.");
    }

    try
    {
        tree.insert(river1, badRiver, false);
        assert(false, "Inserting a node with a parent that already has a right child should throw an exception.");
    }
    catch (const std::invalid_argument &e)
    {
        assert(true, "Inserting a node with a parent that already has a right child should throw an exception.");
    }

    try
    {
        tree.insert(river1, nullptr, true);
        assert(false, "Inserting a null child should throw an exception.");
    }
    catch (const std::invalid_argument &e)
    {
        assert(true, "Inserting a null child should throw an exception.");
    }

    try
    {
        tree.insert(nullptr, river1, true);
        assert(false, "Inserting a root when a root already exists should throw an exception.");
    }
    catch (const std::invalid_argument &e)
    {
        assert(true, "Inserting a root when a root already exists should throw an exception.");
    }

    // Tree printing tests

    std::ostringstream output;
    std::string expected = "Foo River (100 km) \nBaz Dam (50 m, 0 MW) Bar Lake (200 km^2) \n\n";

    tree.print(output);

    assert(output.str() == expected, "Tree print did not match expected output.");

    std::cout << "All tests passed." << std::endl;

    return 0;
}