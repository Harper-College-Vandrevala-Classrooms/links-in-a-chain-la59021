#include "ChainLink.hpp"
#include "LinkedChain.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    ChainLink link_one = ChainLink("red");
    ChainLink link_two = ChainLink("green");
    ChainLink link_three = ChainLink("blue");
    ChainLink link_four = ChainLink("");
    ChainLink link_five = ChainLink("The entire Bee movie script");
    ChainLink link_six = ChainLink("foo");
    ChainLink link_seven = ChainLink("bar");
    ChainLink link_eight = ChainLink("gray");
    ChainLink link_nine = ChainLink("black");
    ChainLink link_ten = ChainLink("0");

    LinkedChain chain_reel[10] = {LinkedChain(&link_one), LinkedChain(&link_two, &chain_reel[0]), LinkedChain(&link_three, &chain_reel[1]), LinkedChain(&link_four, &chain_reel[2]), LinkedChain(&link_five, &chain_reel[3]), LinkedChain(&link_six, &chain_reel[4]), LinkedChain(&link_seven, &chain_reel[5]), LinkedChain(&link_eight, &chain_reel[6]), LinkedChain(&link_nine, &chain_reel[7]), LinkedChain(&link_ten, &chain_reel[8])};
    LinkedChain reel_chain[10] = {LinkedChain(&link_ten), LinkedChain(&link_nine, &reel_chain[0]), LinkedChain(&link_eight, &reel_chain[1]), LinkedChain(&link_seven, &reel_chain[2]), LinkedChain(&link_six, &reel_chain[3]), LinkedChain(&link_five, &reel_chain[4]), LinkedChain(&link_four, &reel_chain[5]), LinkedChain(&link_three, &reel_chain[6]), LinkedChain(&link_two, &reel_chain[7]), LinkedChain(&link_one, &reel_chain[8])};
    LinkedChain push_rear[5] = {LinkedChain(&link_one), LinkedChain(&link_two), LinkedChain(&link_three), LinkedChain(&link_four), LinkedChain(&link_five)};
    for (unsigned long x = 0; x < sizeof(push_rear)/sizeof(LinkedChain)-1; x++) {
        push_rear[x].push_Back(&push_rear[x+1]);
    }
    LinkedChain push_head[5] = {LinkedChain(&link_one), LinkedChain(&link_two), LinkedChain(&link_three), LinkedChain(&link_four), LinkedChain(&link_five)};
    for (unsigned long x = sizeof(push_head)/sizeof(LinkedChain)-1; x > 0; x--) {
        push_head[x].push_Front(&push_head[x-1]);
    }
    

    string check_mark = "[\033[32mO\033[0m]";
    cout << "Method test statuses:" << endl;

    // testing next() method
    assert(chain_reel[0].next() == &chain_reel[1]);
    assert(chain_reel[1].next() == &chain_reel[2]);
    assert(chain_reel[8].next() == &chain_reel[9]);
    assert(chain_reel[9].next() == nullptr);
    assert(chain_reel[0].next()->next() == &chain_reel[2]);
    assert(chain_reel[5].next()->next() == &chain_reel[7]);
    assert(chain_reel[0].next()->next()->next() == &chain_reel[3]);
    assert(chain_reel[3].next()->next()->next() == &chain_reel[6]);
    assert(chain_reel[0].next()->next()->next()->next() == &chain_reel[4]);
    assert(chain_reel[4].next()->next()->next()->next() == &chain_reel[8]);
    cout << check_mark << " next()" << endl;

    // testing prev() method
    assert(reel_chain[9].prev() == &reel_chain[8]);
    assert(reel_chain[8].prev() == &reel_chain[7]);
    assert(reel_chain[1].prev() == &reel_chain[0]);
    assert(reel_chain[0].prev() == nullptr);
    assert(reel_chain[9].prev()->prev() == &reel_chain[7]);
    assert(reel_chain[6].prev()->prev() == &reel_chain[4]);
    assert(reel_chain[9].prev()->prev()->prev() == &reel_chain[6]);
    assert(reel_chain[7].prev()->prev()->prev() == &reel_chain[4]);
    assert(reel_chain[9].prev()->prev()->prev()->prev() == &reel_chain[5]);
    assert(reel_chain[6].prev()->prev()->prev()->prev() == &reel_chain[2]);
    cout << check_mark << " prev()" << endl;

    // testing data() method
    assert(chain_reel[0].data() == &link_one);
    assert(chain_reel[1].data() == &link_two);
    assert(chain_reel[8].data() == &link_nine);
    assert(chain_reel[0].next()->data() == &link_two);
    assert(chain_reel[5].next()->data() == &link_seven);
    assert(reel_chain[9].data() == &link_one);
    assert(reel_chain[8].data() == &link_two);
    assert(reel_chain[1].data() == &link_nine);
    assert(reel_chain[9].prev()->data() == &link_two);
    assert(reel_chain[4].prev()->data() == &link_seven);
    cout << check_mark << " data()" << endl;
    
    // testing get_Color() method
    assert(chain_reel[0].data()->get_Color() == "red");
    assert(chain_reel[1].data()->get_Color() == "green");
    assert(chain_reel[8].data()->get_Color() == "black");
    assert(chain_reel[0].next()->data()->get_Color() == "green");
    assert(chain_reel[5].next()->data()->get_Color() == "bar");
    assert(reel_chain[9].data()->get_Color() == "red");
    assert(reel_chain[8].data()->get_Color() == "green");
    assert(reel_chain[1].data()->get_Color() == "black");
    assert(reel_chain[9].prev()->data()->get_Color() == "green");
    assert(reel_chain[4].prev()->data()->get_Color() == "bar");
    cout << check_mark << " get_Color()" << endl;

    // testing size() method
    assert(chain_reel[0].size() == 9);
    assert(chain_reel[1].size() == 8);
    assert(chain_reel[2].size() == 7);
    assert(chain_reel[3].size() == 6);
    assert(chain_reel[4].size() == 5);
    assert(chain_reel[5].size() == 4);
    assert(chain_reel[6].size() == 3);
    assert(chain_reel[7].size() == 2);
    assert(chain_reel[8].size() == 1);
    assert(chain_reel[9].size() == 0);
    cout << check_mark << " size()" << endl;

    // testing push_Back(*LinkedChain nextLink) method
    assert(push_rear[0].next() == &push_rear[1]);
    assert(push_rear[1].next() == &push_rear[2]);
    assert(push_rear[3].next() == &push_rear[4]);
    assert(push_rear[4].next() == nullptr);
    assert(push_rear[0].next()->next() == &push_rear[2]);
    assert(push_rear[2].next()->next() == &push_rear[4]);
    assert(push_rear[0].next()->next()->next() == &push_rear[3]);
    assert(push_rear[1].next()->next()->next() == &push_rear[4]);
    assert(push_rear[0].next()->next()->next()->next() == &push_rear[4]);
    cout << check_mark << " push_Back(LinkedChain* nextLink)" << endl;

    // // testing push_Front(*LinkedChain prevLink) method
    assert(push_head[0].next() == &push_head[1]);
    assert(push_head[1].next() == &push_head[2]);
    assert(push_head[3].next() == &push_head[4]);
    assert(push_head[4].next() == nullptr);
    assert(push_head[0].next()->next() == &push_head[2]);
    assert(push_head[2].next()->next() == &push_head[4]);
    assert(push_head[0].next()->next()->next() == &push_head[3]);
    assert(push_head[1].next()->next()->next() == &push_head[4]);
    assert(push_head[0].next()->next()->next()->next() == &push_head[4]);
    cout << check_mark << " push_Front(LinkedChain* prevLink)" << endl;
    
    return 0;
}