#include "ChainLink.hpp"
#include "Chain.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    ChainLink linkOne = ChainLink("red");
    ChainLink linkTwo = ChainLink("green");
    ChainLink linkThree = ChainLink("blue");
    ChainLink linkFour = ChainLink("");
    ChainLink linkFive = ChainLink("The entire Bee movie script");
    ChainLink linkSix = ChainLink("foo");
    ChainLink linkSeven = ChainLink("bar");
    ChainLink linkEight = ChainLink("grey");
    ChainLink linkNine = ChainLink("black");
    ChainLink linkTen = ChainLink("0");

    Chain chainReel[10] = {Chain(&linkOne), Chain(&linkTwo, &chainReel[0]), Chain(&linkThree, &chainReel[1]), Chain(&linkFour, &chainReel[2]), Chain(&linkFive, &chainReel[3]), Chain(&linkSix, &chainReel[4]), Chain(&linkSeven, &chainReel[5]), Chain(&linkEight, &chainReel[6]), Chain(&linkNine, &chainReel[7]), Chain(&linkTen, &chainReel[8])};
    Chain reelChain[10] = {Chain(&linkTen), Chain(&linkNine, &reelChain[0]), Chain(&linkEight, &reelChain[1]), Chain(&linkSeven, &reelChain[2]), Chain(&linkSix, &reelChain[3]), Chain(&linkFive, &reelChain[4]), Chain(&linkFour, &reelChain[5]), Chain(&linkThree, &reelChain[6]), Chain(&linkTwo, &reelChain[7]), Chain(&linkOne, &reelChain[8])};
    Chain push_pull[5] = {Chain(&linkOne), Chain(&linkTwo), Chain(&linkThree), Chain(&linkFour), Chain(&linkFive)};
    push_pull[0].push_back(&push_pull[1]);
    cout << push_pull[1].data().get_color() << endl;
    cout << push_pull[1].next().data().get_color() << endl;
    cout << chainReel[2].size() << endl;

    return 0;
}