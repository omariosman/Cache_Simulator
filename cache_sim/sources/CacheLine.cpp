#include <CacheLine.h>

CacheLine::CacheLine (bool _wb)
{
    v = false;
    tag =0;
    hits = 0;
    misses = 0;
    cache_reads = 0;
    cache_writes = 0;
    mem_reads = 0;
    mem_writes = 0;
    wb = _wb;
}
void CacheLine::handle_miss (uint64_t p_tag, char mode)
{
std::cout << "handle miss" << std::endl;
    //Write your code here
	tag = p_tag;
	v = 1;
	if (mode == 'R'){
		mem_reads++;
		

	} else if (mode == 'W'){
		mem_writes++;
	}

}

bool CacheLine::valid()
{
    return v;
}
uint64_t CacheLine::getTag()
{
    return tag;
}
uint64_t CacheLine::getHits()
{
    return hits;
}
uint64_t CacheLine::getMisses()
{
    return misses;
}
uint64_t CacheLine::getCacheReads()
{
    return cache_reads;
}
uint64_t CacheLine::getCacheWrites()
{
    return cache_writes;
}
uint64_t CacheLine::getMEMReads()
{
    return mem_reads;
}
uint64_t CacheLine::getMEMWrites()
{
    return mem_writes;
}
void CacheLine::access (uint64_t p_tag,char mode)
{
std::cout << "cache line access" << std::endl;
   //Write your code here
	if ((v == 1) && (p_tag == tag)){
		std::cout << "Hit" << std::endl;	
		hits++;	
		if (mode == 'R'){
			cache_reads++;
		} else if (mode == 'W'){
			cache_writes++;
		}	
	} else {
		std::cout << "Miss" << std::endl;
		misses++;
		handle_miss(p_tag, mode);
	}
}


void CacheLine::write_back(){

}

void CacheLine::write_through(){

}
/*
static void CacheLine::printTotal(){
	std::cout <<  "Total Hits: " << hits << std::endl;
	std::cout << "Total Misses: " << this->getMisses() <<std::endl;
	std::cout << "Total Memory Reads: " <<this->getMEMReads() << std::endl;
	std::cout << "Total Memory Writes: "<< this->getMEMWrites() std::endl;
	std::cout << "Total Cache Reads: " << this->getCacheReads() std::endl;
	std::cout << "Total Cache Writes: " << this->getCacheWrites() std::endl;	
}
*/
CacheLine::~CacheLine()
{

}
