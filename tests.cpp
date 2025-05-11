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

void test_tree_delete() {
    Tree tree;
    tree.reset();

    RiverNode *river = new RiverNode();
    river->name = "Amazon";
    river->length = 6400;
    tree.insert(nullptr, river, true);

    DamNode *dam = new DamNode();
    dam->name = "Tucurui Dam";
    dam->height = 78;
    dam->power = 8370;
    tree.insert(river, dam, true);

    LakeNode *lake = new LakeNode();
    lake->name = "Atlantic Ocean";
    lake->area = 106500000;
    tree.insert(river, lake, false);

    // Test delete operation
    tree.remove(dam);
    
    assert(river->left == nullptr, "Dam node was not properly deleted");
    
    // Test deleting a node with children (should fail)
    try {
        tree.remove(river);
        assert(false, "Removing a node with children should throw an exception");
    } catch (const std::invalid_argument &e) {
        assert(true, "Correctly throws exception when removing a node with children");
    }
    
    // Test deleting leaf node
    tree.remove(lake);
    assert(river->right == nullptr, "Lake node was not properly deleted");
    
    // Test deleting root when it's the only node
    tree.remove(river);
    assert(tree.getRoot() == nullptr, "Root node was not properly deleted");
}

void test_tree_find() {
    Tree tree;
    tree.reset();

    RiverNode *nile = new RiverNode();
    nile->name = "Nile";
    nile->length = 6650;
    tree.insert(nullptr, nile, true);

    DamNode *aswan = new DamNode();
    aswan->name = "Aswan Dam";
    aswan->height = 111;
    aswan->power = 2100;
    tree.insert(nile, aswan, true);

    LakeNode *mediterranean = new LakeNode();
    mediterranean->name = "Mediterranean Sea";
    mediterranean->area = 2500000;
    tree.insert(nile, mediterranean, false);

    RiverNode *yangtze = new RiverNode();
    yangtze->name = "Yangtze";
    yangtze->length = 6300;
    tree.insert(mediterranean, yangtze, true);

    DamNode *threeGorges = new DamNode();
    threeGorges->name = "Three Gorges Dam";
    threeGorges->height = 185;
    threeGorges->power = 22500;
    tree.insert(yangtze, threeGorges, true);

    // Test find by name
    Node* foundNode = tree.findByName("Three Gorges Dam");
    assert(foundNode == threeGorges, "Failed to find Three Gorges Dam by name");
    
    foundNode = tree.findByName("Nile");
    assert(foundNode == nile, "Failed to find Nile by name");
    
    foundNode = tree.findByName("Non-existent River");
    assert(foundNode == nullptr, "Should return nullptr for non-existent node");
    
    // Test ancestor checks
    bool isAncestor = tree.isAncestor(nile, threeGorges);
    assert(isAncestor, "Nile should be an ancestor of Three Gorges Dam");
    
    isAncestor = tree.isAncestor(threeGorges, nile);
    assert(!isAncestor, "Three Gorges Dam should not be an ancestor of Nile");
}

void test_complex_tree() {
    Tree tree;
    tree.reset();

    // Create a complex river system
    RiverNode *congo = new RiverNode();
    congo->name = "Congo River";
    congo->length = 4700;
    tree.insert(nullptr, congo, true);

    DamNode *inga = new DamNode();
    inga->name = "Inga Dam";
    inga->height = 150;
    inga->power = 40000;
    tree.insert(congo, inga, true);

    LakeNode *atlantic = new LakeNode();
    atlantic->name = "Atlantic Ocean";
    atlantic->area = 106500000;
    tree.insert(congo, atlantic, false);

    RiverNode *kasai = new RiverNode();
    kasai->name = "Kasai River";
    kasai->length = 2153;
    tree.insert(inga, kasai, false);

    LakeNode *maiNdombe = new LakeNode();
    maiNdombe->name = "Mai-Ndombe Lake";
    maiNdombe->area = 2300;
    tree.insert(kasai, maiNdombe, true);

    RiverNode *lualaba = new RiverNode();
    lualaba->name = "Lualaba River";
    lualaba->length = 1800;
    tree.insert(inga, lualaba, true);

    DamNode *nzilo = new DamNode();
    nzilo->name = "Nzilo Dam";
    nzilo->height = 74;
    nzilo->power = 108;
    tree.insert(lualaba, nzilo, true);

    // Test the depth of the tree
    int depth = tree.depth();
    assert(depth == 4, "Tree depth should be 4");

    // Test node counts
    int riverCount = tree.countNodeType<RiverNode>();
    assert(riverCount == 3, "Should have 3 river nodes");

    int damCount = tree.countNodeType<DamNode>();
    assert(damCount == 2, "Should have 2 dam nodes");

    int lakeCount = tree.countNodeType<LakeNode>();
    assert(lakeCount == 2, "Should have 2 lake nodes");

    // Test total power capacity
    double totalPower = tree.calculateTotalPower();
    assert(totalPower == 40108, "Total power should be 40108 MW");

    // Verify the structure with print and comparison
    std::ostringstream output;
    tree.print(output);
    std::string expected = 
        "Congo River (4700 km) \n"
        "Inga Dam (150 m, 40000 MW) Atlantic Ocean (106500000 km^2) \n"
        "Lualaba River (1800 km) Kasai River (2153 km) \n"
        "Nzilo Dam (74 m, 108 MW)  Mai-Ndombe Lake (2300 km^2) \n\n";
    assert(output.str() == expected, "Complex tree print output doesn't match expected");
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

    //DevOps extra tests for 10 total

    //DevOps extra tests for 10 total

    // Tree printing tests

    std::ostringstream output;
    std::string expected = "Foo River (100 km) \nBaz Dam (50 m, 0 MW) Bar Lake (200 km^2) \n\n";

    tree.print(output);

    assert(output.str() == expected, "Tree print did not match expected output.");

    test_tree_remove();
    test_tree_find();
    test_tree_complex();

    std::cout << "All tests passed." << std::endl;

    return 0;
}