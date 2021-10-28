#include <iostream>

int main()
{
    constexpr unsigned packets_in_stack = 8;
    constexpr unsigned packets_in_box = packets_in_stack * 40;
    constexpr unsigned packet_price = 12, stack_price = 82, box_price = 3050;

    unsigned n;
    std::cin>>n;
    unsigned count_packets, count_stacks, count_boxes;

    // it is always better to buy larger than smaller
    
    count_boxes = n/packets_in_box;
    n -= count_boxes*packets_in_box;
    count_stacks = n/packets_in_stack;
    n -= count_stacks*packets_in_stack;
    count_packets = n;

//  std::cout << count_boxes << ' ' << count_stacks << ' ' << count_packets << std::endl;

    unsigned current_price = count_boxes*box_price + count_stacks*stack_price + count_packets*packet_price;

    if(count_boxes*box_price + (count_stacks+1)*stack_price < current_price)
    {
        count_packets = 0;
        ++count_stacks;
        current_price = count_boxes*box_price + count_stacks*stack_price;
    }

    if((count_boxes+1) * box_price < current_price)
    {
        count_packets = 0;
        count_stacks = 0;
        ++count_boxes;
        // current_price = count_boxes*box_price
    }

    std::cout << count_boxes << ' ' << count_stacks << ' ' << count_packets << std::endl;

    return 0;
}
