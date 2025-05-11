#include "rivers.h"

Tree::Tree()
{
    root = nullptr;

    RiverNode *C1 = new RiverNode();
    C1->name = "Columbia River";
    C1->length = -1;

    RiverNode *Spillimacheen = new RiverNode();
    Spillimacheen->name = "Spillimacheen River";
    Spillimacheen->length = 118;

    RiverNode *c2 = new RiverNode();
    c2->name = "Columbia River";
    c2->length = -1;

    RiverNode *Kootenay = new RiverNode();
    Kootenay->name = "Kootenay River";
    Kootenay->length = 780;

    RiverNode *c3 = new RiverNode();
    c3->name = "Columbia River";
    c3->length = -1;

    RiverNode *Pend_Orielle = new RiverNode();
    Pend_Orielle->name = "Pend Orielle River";
    Pend_Orielle->length = 771;

    RiverNode *c4 = new RiverNode();
    c4->name = "Columbia River";
    c4->length = -1;

    RiverNode *Kettle = new RiverNode();
    Kettle->name = "Kettle River";
    Kettle->length = 282;

    RiverNode *c5 = new RiverNode();
    c5->name = "Columbia River";
    c5->length = -1;

    RiverNode *Spokane = new RiverNode();
    Spokane->name = "Spokane River";
    Spokane->length = 179;

    RiverNode *c6 = new RiverNode();
    c6->name = "Columbia River";
    c6->length = -1;

    RiverNode *Okanogan = new RiverNode();
    Okanogan->name = "Okanogan River";
    Okanogan->length = 185;

    RiverNode *c7 = new RiverNode();
    c7->name = "Columbia River";
    c7->length = -1;

    RiverNode *Methow = new RiverNode();
    Methow->name = "Methow River";
    Methow->length = 129;

    RiverNode *c8 = new RiverNode();
    c8->name = "Columbia River";
    c8->length = -1;

    RiverNode *Crab = new RiverNode();
    Crab->name = "Crab Creek";
    Crab->length = 262;

    RiverNode *c9 = new RiverNode();
    c9->name = "Columbia River";
    c9->length = -1;

    RiverNode *Yakima = new RiverNode();
    Yakima->name = "Yakima River";
    Yakima->length = 344;

    RiverNode *c10 = new RiverNode();
    c10->name = "Columbia River";
    c10->length = -1;

    RiverNode *Snake = new RiverNode();
    Snake->name = "Snake River";
    Snake->length = 1735;

    RiverNode *c11 = new RiverNode();
    c11->name = "Columbia River";
    c11->length = -1;

    RiverNode *Umatilla = new RiverNode();
    Umatilla->name = "Umatilla River";
    Umatilla->length = 143;

    RiverNode *c12 = new RiverNode();
    c12->name = "Columbia River";
    c12->length = -1;

    RiverNode *Willow = new RiverNode();
    Willow->name = "Willow Creek";
    Willow->length = 127;

    RiverNode *c13 = new RiverNode();
    c13->name = "Columbia River";
    c13->length = -1;

    RiverNode *John_Day = new RiverNode();
    John_Day->name = "John Day River";
    John_Day->length = 457;

    RiverNode *c14 = new RiverNode();
    c14->name = "Columbia River";
    c14->length = -1;

    RiverNode *Deschutes = new RiverNode();
    Deschutes->name = "Deschutes River";
    Deschutes->length = 406;

    RiverNode *c15 = new RiverNode();
    c15->name = "Columbia River";
    c15->length = -1;

    RiverNode *Klickitat = new RiverNode();
    Klickitat->name = "Klickitat River";
    Klickitat->length = 154;

    RiverNode *c16 = new RiverNode();
    c16->name = "Columbia River";
    c16->length = -1;

    RiverNode *Willamette = new RiverNode();
    Willamette->name = "Willamette River";
    Willamette->length = 301;

    RiverNode *c17 = new RiverNode();
    c17->name = "Columbia River";
    c17->length = -1;

    RiverNode *Lewis = new RiverNode();
    Lewis->name = "Lewis River";
    Lewis->length = 153;

    RiverNode *c18 = new RiverNode();
    c18->name = "Columbia River";
    c18->length = -1;

    RiverNode *Colitz = new RiverNode();
    Colitz->name = "Colitz River";
    Colitz->length = 169;

    // Because rivers and dams are not included, they are commented out to prevent memory leaks

    // DamNode *micaDam = new DamNode();
    // micaDam->name = "Mica Dam";
    // micaDam->height = 240;
    // micaDam->power = 2805;

    // DamNode *revelstokeDam = new DamNode();
    // revelstokeDam->name = "Revelstoke Dam";
    // revelstokeDam->height = 175;
    // revelstokeDam->power = 2480;

    // DamNode *grandCouleeDam = new DamNode();
    // grandCouleeDam->name = "Grand Coulee Dam";
    // grandCouleeDam->height = 170;
    // grandCouleeDam->power = 6809;

    // DamNode *chiefJosephDam = new DamNode();
    // chiefJosephDam->name = "Chief Joseph Dam";
    // chiefJosephDam->height = 72;
    // chiefJosephDam->power = 2620;

    // DamNode *wellsDam = new DamNode();
    // wellsDam->name = "Wells Dam";
    // wellsDam->height = 49;
    // wellsDam->power = 840;

    // DamNode *rockyReachDam = new DamNode();
    // rockyReachDam->name = "Rocky Reach Dam";
    // rockyReachDam->height = 40;
    // rockyReachDam->power = 1287;

    // DamNode *rockIslandDam = new DamNode();
    // rockIslandDam->name = "Rock Island Dam";
    // rockIslandDam->height = 41;
    // rockIslandDam->power = 660;

    // DamNode *wanaapumDam = new DamNode();
    // wanaapumDam->name = "Wanaapum Dam";
    // wanaapumDam->height = 56;
    // wanaapumDam->power = 1092;

    // DamNode *priestRapidsDam = new DamNode();
    // priestRapidsDam->name = "Priest Rapids Dam";
    // priestRapidsDam->height = 54;
    // priestRapidsDam->power = 956;

    // DamNode *mcNaryDam = new DamNode();
    // mcNaryDam->name = "McNary Dam";
    // mcNaryDam->height = 56;
    // mcNaryDam->power = 1133;

    // DamNode *johnDayDam = new DamNode();
    // johnDayDam->name = "John Day Dam";
    // johnDayDam->height = 56;
    // johnDayDam->power = 2485;

    // DamNode *theDallesDam = new DamNode();
    // theDallesDam->name = "The Dalles Dam";
    // theDallesDam->height = 79;
    // theDallesDam->power = 2038;

    // DamNode *bonnevilleDam = new DamNode();
    // bonnevilleDam->name = "Bonneville Dam";
    // bonnevilleDam->height = 60;
    // bonnevilleDam->power = 1190;

    // DamNode *brownleeDam = new DamNode();
    // brownleeDam->name = "Brownlee Dam";
    // brownleeDam->height = 130;
    // brownleeDam->power = 585;

    // DamNode *lowerGraniteDam = new DamNode();
    // lowerGraniteDam->name = "Lower Granite Dam";
    // lowerGraniteDam->height = 55;
    // lowerGraniteDam->power = 932;

    // DamNode *littleGooseDam = new DamNode();
    // littleGooseDam->name = "Little Goose Dam";
    // littleGooseDam->height = 77;
    // littleGooseDam->power = 932;

    // DamNode *lowerMonumentalDam = new DamNode();
    // lowerMonumentalDam->name = "Lower Monumental Dam";
    // lowerMonumentalDam->height = 46;
    // lowerMonumentalDam->power = 930;

    // DamNode *iceHarborDam = new DamNode();
    // iceHarborDam->name = "Ice Harbor Dam";
    // iceHarborDam->height = 65;
    // iceHarborDam->power = 693;

    // DamNode *libbyDam = new DamNode();
    // libbyDam->name = "Libby Dam";
    // libbyDam->height = 130;
    // libbyDam->power = 604;

    // DamNode *kootenayDam = new DamNode();
    // kootenayDam->name = "Kootenay Canal Generating Station";
    // kootenayDam->height = 84;
    // kootenayDam->power = 583;

    // DamNode *noxonDam = new DamNode();
    // noxonDam->name = "Noxon Rapids Dam";
    // noxonDam->height = 79;
    // noxonDam->power = 527;

    // DamNode *boundaryDam = new DamNode();
    // boundaryDam->name = "Boundary Dam";
    // boundaryDam->height = 100;
    // boundaryDam->power = 1040;

    // DamNode *sevenMileDam = new DamNode();
    // sevenMileDam->name = "Seven Mile Dam";
    // sevenMileDam->height = 79;
    // sevenMileDam->power = 848;

    // LakeNode *revelstokeLake = new LakeNode();
    // revelstokeLake->name = "Lake Revelstoke";
    // revelstokeLake->area = 115;

    // LakeNode *fdrLake = new LakeNode();
    // fdrLake->name = "Franklin D. Roosevelt Lake";
    // fdrLake->area = 320;

    // LakeNode *lakeKoo = new LakeNode();
    // lakeKoo->name = "Lake Koocanusa";
    // lakeKoo->area = 188;

    // LakeNode *kootLake = new LakeNode();
    // kootLake->name = "Kootenay Lake";
    // kootLake->area = 400;

    // LakeNode *flatheadLake = new LakeNode();
    // flatheadLake->name = "Flathead Lake";
    // flatheadLake->area = 510;

    // LakeNode *lpoLake = new LakeNode();
    // lpoLake->name = "Lake Pend Oreille";
    // fdrLake->area = 383;

    // LakeNode *jacksonLake = new LakeNode();
    // jacksonLake->name = "Jackson Lake";
    // fdrLake->area = 103;

    // LakeNode *kinbasketLake = new LakeNode();
    // kinbasketLake->name = "Kinbasket Lake";
    // kinbasketLake->area = 430;

    // LakeNode *billychinookLake = new LakeNode();
    // billychinookLake->name = "Billy Chinook Lake";
    // billychinookLake->area = 121;

    // LakeNode *lakeChelan = new LakeNode();
    // lakeChelan->name = "Lake Chelan";
    // lakeChelan->area = 135;

    // LakeNode *okanaganLake = new LakeNode();
    // okanaganLake->name = "Okanagan Lake";
    // okanaganLake->area = 351;

    // LakeNode *lakeCoeurdAlene = new LakeNode();
    // lakeCoeurdAlene->name = "Lake Coeur D'Alene";
    // lakeCoeurdAlene->area = 129;

    insert(nullptr, C1, false);
    insert(C1, Spillimacheen, false);
    insert(C1, c2, true);
    insert(c2, Kootenay, false);
    insert(c2, c3, true);
    insert(c3, Pend_Orielle, false);
    insert(c3, c4, true);
    insert(c4, Kettle, false);
    insert(c4, c5, true);
    insert(c5, Spokane, false);
    insert(c5, c6, true);
    insert(c6, Okanogan, false);
    insert(c6, c7, true);
    insert(c7, Methow, false);
    insert(c7, c8, true);
    insert(c8, Crab, false);
    insert(c8, c9, true);
    insert(c9, Yakima, false);
    insert(c9, c10, true);
    insert(c10, Snake, false);
    insert(c10, c11, true);
    insert(c11, Umatilla, false);
    insert(c11, c12, true);
    insert(c12, Willow, false);
    insert(c12, c13, true);
    insert(c13, John_Day, false);
    insert(c13, c14, true);
    insert(c14, Deschutes, false);
    insert(c14, c15, true);
    insert(c15, Klickitat, false);
    insert(c15, c16, true);
    insert(c16, Willamette, false);
    insert(c16, c17, true);
    insert(c17, Lewis, false);
    insert(c17, c18, true);
    insert(c18, Colitz, false);
}

void Tree::insert(Node *parent, Node *child, bool left)
{
    // Make sure arguments are valid

    if (parent == nullptr && root != nullptr)
    {
        throw std::invalid_argument("Root already exists.");
    }

    if (child == nullptr)
    {
        throw std::invalid_argument("Child cannot be null.");
    }

    // Have the root case here because parent will be null
    if (parent == nullptr)
    {
        root = child;
        return;
    }

    if (left && parent->left != nullptr)
    {
        throw std::invalid_argument("Parent already has a left child.");
    }

    if (!left && parent->right != nullptr)
    {
        throw std::invalid_argument("Parent already has a right child.");
    }

    // Insert the child

    if (left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
}

void Tree::print(std::ostream &output) const
{
    // Use a queue to do a level-order traversal

    std::queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            output << std::endl;

            if (q.empty())
            {
                break;
            }

            q.push(nullptr);
            continue;
        }

        output << node->to_string() << " ";

        if (node->left != nullptr)
        {
            q.push(node->left);
        }

        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }

    output << std::endl;
}

int get_user_option(const std::vector<std::string> &options)
{
    if (options.empty())
    {
        throw std::logic_error("No options provided");
    }

    int choice = -1;
    std::string input = "";

    // Print the options
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << (i + 1) << ") " << options[i] << std::endl;
    }

    std::cout << "Enter your choice:\n"
              << std::endl;

    // Get the user's choice and validate it
    while (choice < 0 || choice >= options.size())
    {
        // ANSI escape codes to move the cursor up one line, then clear the line
        // Based on https://stackoverflow.com/a/3277094
        std::cout << "\x1b[A\r\e[K" << std::flush;

        std::getline(std::cin, input);

        try
        {
            choice = std::stoi(input) - 1;
        }
        catch (std::invalid_argument &e)
        {
            // If the user didn't enter a number, just loop again
            continue;
        }
    }

    std::cout << std::endl;

    return choice;
}

bool navigate_tree(const Tree &tree)
{
    std::vector<std::string> options;
    std::stack<Node *> history;
    history.push(tree.getRoot());

    // If the tree is empty, throw an exception
    if (history.top() == nullptr)
    {
        throw std::invalid_argument("Tree is empty");
    }

    while (true)
    {
        options = {"Main Menu", "Quit"};

        // Add options for the parent and children if they exist
        if (history.size() > 1)
        {
            // Get the parent node
            Node *current = history.top();
            history.pop();
            Node *parent = history.top();
            history.push(current);

            options.insert(options.begin(), "Go back to " + parent->to_string());
        }

        if (history.top()->right != nullptr)
        {
            options.insert(options.begin(), "Split off to " + history.top()->right->to_string());
        }

        if (history.top()->left != nullptr)
        {
            options.insert(options.begin(), "Continue to " + history.top()->left->to_string());
        }

        std::cout << "You are at: " << history.top()->to_string() << std::endl;

        int choice = get_user_option(options);

        if (options[choice] == "Quit")
        {
            return true;
        }
        else if (options[choice] == "Main Menu")
        {
            return false;
        }
        else if (options[choice].at(0) == 'C')
        {
            history.push(history.top()->left);
        }
        else if (options[choice].at(0) == 'S')
        {
            history.push(history.top()->right);
        }
        else if (options[choice].at(0) == 'G')
        {
            history.pop();
        }
    }
}
