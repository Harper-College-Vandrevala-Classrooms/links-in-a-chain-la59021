#include "ChainLink.hpp"
#include "Chain.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    ChainLink link_one = ChainLink("red");
    Chain *node_one = new Chain(&link_one);

    ChainLink link_two = ChainLink("blue");
    Chain *node_two = new Chain(&link_two, node_one);

    ChainLink link_three = ChainLink("green");
    Chain *node_three = new Chain(&link_three, node_two);

    // This is to silence a warning about node_three being unused;
    node_three->data();

    // Returns the second ChainLink in the list
    Chain retrieved_node = node_one->next();
    ChainLink retrieved_link = retrieved_node.data();
    assert(retrieved_link.get_color() == "blue");

    // Returns the third ChainLink in the list
    Chain another_retrieved_node = node_one->next().next();
    ChainLink another_retrieved_link = another_retrieved_node.data();
    assert(another_retrieved_link.get_color() == "green");

    cout << "The example works." << endl;
    return 0;
}