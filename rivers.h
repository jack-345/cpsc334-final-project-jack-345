#ifndef RIVERS_H
#define RIVERS_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>

/**
 * A node in a binary tree.
 */
struct Node
{
    Node *left;
    Node *right;

    Node() : left(nullptr), right(nullptr) {}
    Node(Node *left, Node *right) : left(left), right(right) {}

    ~Node()
    {
        delete left;
        delete right;
    }

    /**
     * Returns a human-readable string representation of the node.
     */
    virtual std::string to_string() const = 0;
};

/**
 * A node that represents a river.
 */
struct RiverNode : public Node
{
    /**
     * The name of the river.
     */
    std::string name;

    /**
     * The length in kilometers.
     */
    int length;

    std::string to_string() const override
    {
        // Don't print the length if it's negative
        if (length < 0)
        {
            return name;
        }

        return name + " (" + std::to_string(length) + " km)";
    }
};

/**
 * A node that represents a lake or reservoir.
 */
struct LakeNode : public Node
{
    /**
     * The name of the lake or reservoir.
     */
    std::string name;

    /**
     * The area in square kilometers.
     */
    int area;

    std::string to_string() const override
    {
        return name + " (" + std::to_string(area) + " km^2)";
    }
};

/**
 * A node that represents a Dam.
 */
struct DamNode : public Node
{
    /**
     * The name of the dam.
     */
    std::string name;

    /**
     * The height in meters.
     */
    int height;

    /**
     * The power output in megawatts.
     */
    int power;

    std::string to_string() const override
    {
        return name + " (" + std::to_string(height) + " m, " + std::to_string(power) + " MW)";
    }
};

/**
 * A binary tree.
 */
class Tree
{
    Node *root;

public:
    Tree();

    ~Tree()
    {
        delete root;
    }

    /**
     * Deletes the root of the tree and sets it to null.
     */
    void reset()
    {
        delete root;
        root = nullptr;
    }

    /**
     * Returns the root of the tree.
     */
    Node *getRoot() const
    {
        return root;
    }

    /**
     * Inserts the given node as the child of the given parent node.
     * It's assumed that the parent node will have a free space for the given node to go.
     * If the parent agrument is null, the child will be the root of the tree.
     *
     * @param parent The node that will be the parent.
     * @param child The node to insert.
     * @param left If true, the child will be to the left of the parent. It will go to the right if false.
     *
     * @throws std::invalid_argument If any of the arguments are invalid.
     */
    void insert(Node *parent, Node *child, bool left);

    /**
     * Prints the tree in a human-readable format to the output stream.
     *
     * @param output The output stream to print to.
     */
    void print(std::ostream &output) const;
};

/**
 * Get the user's choice from a list of options.
 *
 * Because this function uses ANSI escape codes, some terminals may not behave as expected.
 *
 * @param options A vector of strings representing the options to choose from.
 * @return The index of the chosen option.
 *
 * @throws std::logic_error If no options are provided.
 */
int get_user_option(const std::vector<std::string> &options);

/**
 * Allows the user to navigate the tree by selecting nodes to traverse.
 *
 * @param tree The tree to navigate.
 * @return True if the user wants to quit, false if they just want to go back to the main menu.
 *
 * @throws std::invalid_argument If the tree is empty.
 */
bool navigate_tree(const Tree &tree);

#endif
