#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using IP = std::vector<std::string>;
using IP_Pool = std::vector<std::vector<std::string>>;
enum class ESortOctetNumber { FIRST = 0, SECOND, THIRD, FOURTH };

void ShowIpPool(const IP_Pool& ip_pool) noexcept
{
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }

            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

IP_Pool Get_IP_Poll(IP_Pool& ipPool, ESortOctetNumber SortOctetNumber, std::size_t Size)
{
    IP_Pool ret_ip_pool;

    auto it = std::begin(ipPool);

    while( it != std::end(ipPool) )
    {
        if((*it)[static_cast<std::size_t>(SortOctetNumber)].size() == Size)
        {
            ret_ip_pool.push_back(std::move(*it));
            it = ipPool.erase(it);
        }
        else
        {
            ++it;
        }
    }

    return ret_ip_pool;
}

void ReverseLexGraphSort(IP_Pool& ip_pool, ESortOctetNumber SortOctetNumber);

void SortDuplicates(IP_Pool& ipPool, ESortOctetNumber InOctet)
{
    if(InOctet == ESortOctetNumber::FOURTH)
    {
        return;
    }

    auto Octet = static_cast<std::size_t>(InOctet);
    auto it = std::begin(ipPool);

    while(it != std::end(ipPool) && std::next(it) != std::end(ipPool))
    {
        if((*it)[Octet] == (*(std::next(it)))[Octet])
        {

            IP_Pool duplicates_pool{std::move(*it), std::move(*std::next(it))};

            auto should_copy_it = std::next(std::next(it));


            while( should_copy_it != std::end(ipPool) )
            {
                if(duplicates_pool[0][Octet] == (*(should_copy_it))[Octet])
                {
                    duplicates_pool.push_back(std::move(*should_copy_it));
                    ++should_copy_it;
                }
                else
                {
                    break;
                }
            }


            ESortOctetNumber SortOctet;

            switch(InOctet)
            {
                case ESortOctetNumber::FIRST : SortOctet = ESortOctetNumber::SECOND; break;
                case ESortOctetNumber::SECOND: SortOctet = ESortOctetNumber::THIRD; break;
                case ESortOctetNumber::THIRD : SortOctet = ESortOctetNumber::FOURTH; break;
            }

            ReverseLexGraphSort(duplicates_pool, SortOctet);


            auto copy_until_exclude_it = should_copy_it;

            for(auto it_in_dub_pool = std::begin(duplicates_pool);
                it != copy_until_exclude_it;
                ++it, ++it_in_dub_pool)
            {
                *it = std::move(*it_in_dub_pool);
            }



            if(copy_until_exclude_it == std::end(ipPool) || std::next(it) == std::end(ipPool))
            {
                break;
            }

            continue;

        }

        ++it;
    }
}

void SortIPPool(IP_Pool& ipPool, ESortOctetNumber SortOctet)
{

    std::sort(ipPool.begin(),ipPool.end(),
            [OctetNumber = static_cast<std::size_t>(SortOctet)]
            (std::vector<std::string>& left, std::vector<std::string>& right)
            {
                return left[OctetNumber] > right[OctetNumber];
            });

    SortDuplicates(ipPool,SortOctet);


}

void SortIPPool(IP_Pool& ipPool, ESortOctetNumber SortOctetNumber, std::size_t Size)
{
    auto ip_pool_with_Size = Get_IP_Poll(ipPool,SortOctetNumber, Size);
    SortIPPool(ip_pool_with_Size,SortOctetNumber);

    std::copy(std::make_move_iterator(ip_pool_with_Size.begin()),
              std::make_move_iterator(ip_pool_with_Size.end()),
              std::back_inserter(ipPool));
}

void ReverseLexGraphSort(IP_Pool& ip_pool, ESortOctetNumber SortOctetNumber)
{
    SortIPPool(ip_pool,SortOctetNumber,3);
    SortIPPool(ip_pool,SortOctetNumber,2);
    SortIPPool(ip_pool,SortOctetNumber,1);
}


template<typename T>
void UnpackIP(IP& ip, T firstArg)
{
    ip.push_back(std::to_string(firstArg));
}

template<typename T, typename... Tp>
void UnpackIP( IP& ip, T firstArg, Tp... args)
{
    UnpackIP(ip,firstArg);
    UnpackIP(ip, args...);
}



template<typename... Tp>
void Filter(const IP_Pool& ipPool, Tp... tp)
{
        if(sizeof...(tp) > 4)
        {
            return;
        }

    IP filter_ip;
    UnpackIP(filter_ip,tp...);

    IP_Pool filtered_ip_pool;

    for(const auto& ip : ipPool)
    {
        for(std::size_t octet{}; octet < filter_ip.size(); ++octet)
        {
            if(ip[octet] != filter_ip[octet])
            {
                break;
            }
            else
            {
                if(octet == (filter_ip.size() - 1))
                {
                    filtered_ip_pool.push_back(ip);
                }
            }
        }
    }

    if(filter_ip.size() != 4)
    {
        ESortOctetNumber SortOctet;

        switch (filter_ip.size())
        {
            case 1 : SortOctet = ESortOctetNumber::SECOND; break;
            case 2 : SortOctet = ESortOctetNumber::THIRD; break;
            case 3 : SortOctet = ESortOctetNumber::FOURTH; break;

            default: std::cout << "What the hell man?\n"; break;
        }

        ReverseLexGraphSort(filtered_ip_pool, SortOctet);
    }

    ShowIpPool(filtered_ip_pool);

}


void FilterAny(const IP_Pool& ipPool, unsigned char byte)
{
    auto byte_string_rep = std::to_string(byte);
    IP_Pool filtered_any_pool;

    for(const auto& ip : ipPool)
    {
        for(const auto& octet: ip)
        {
            if(octet == byte_string_rep)
            {
                filtered_any_pool.push_back(ip);
                break;
            }
        }
    }

    ReverseLexGraphSort(filtered_any_pool,ESortOctetNumber::FIRST);
    ShowIpPool(filtered_any_pool);

}


int main(int argc, char const *argv[])
{

    try
    {
        IP_Pool ip_pool;


        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        std::cout << "=============REVERSE_SORT_START=============\n";
        ReverseLexGraphSort(ip_pool,ESortOctetNumber::FIRST);
        ShowIpPool(ip_pool);
        std::cout << "=============REVERSE_END_START=============\n";

        std::cout << "=============FILTER_1_START=============\n";
        Filter(ip_pool,1);
        std::cout << "=============FILTER_1_END=============\n";

        std::cout << "=============FILTER_46_70_START=============\n";
        Filter(ip_pool,46,70);
        std::cout << "=============FILTER_46_70_END=============\n";

        std::cout << "=============FILTER_ANY_START=============\n";
        FilterAny(ip_pool,46);
        std::cout << "=============FILTER_ANY_END=============\n";

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
