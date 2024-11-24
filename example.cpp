#include "ChainLink.hpp"
#include "LinkedChain.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    ChainLink link_one = ChainLink("red");
    LinkedChain *node_one = new LinkedChain(&link_one);

    ChainLink link_two = ChainLink("blue");
    LinkedChain *node_two = new LinkedChain(&link_two, node_one);

    ChainLink link_three = ChainLink("green");
    LinkedChain *node_three = new LinkedChain(&link_three, node_two);

    // This is to silence a warning about node_three being unused;
    node_three->data();

    // Returns the second ChainLink in the list
    LinkedChain retrieved_node = *node_one->next();
    ChainLink retrieved_link = *retrieved_node.data();
    assert(retrieved_link.get_Color() == "blue");

    // Returns the third ChainLink in the list
    LinkedChain another_retrieved_node = *node_one->next()->next();
    ChainLink another_retrieved_link = *another_retrieved_node.data();
    assert(another_retrieved_link.get_Color() == "green");

    cout << "The example works." << endl;
    return 0;
}