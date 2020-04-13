#include <DirectMap.h>
#include<CacheLine.h>
#include <Utils.h>


DirectMap::DirectMap (uint16_t p_cache_line_size , uint16_t p_cache_size, bool _wb)
{
std::cout << "direct map constructor" << std::endl;
	//Write your code here
	//Constructor
	cache_line_size = p_cache_line_size;
	cache_size      = p_cache_size;
	size  = 0;
	for (int i =0; i < cache_size; i++){
		cache[i] = new CacheLine();
	}
	//call write back or write through
	   
	
    
}
void DirectMap::access (uint64_t full_address,char mode)
{
std::cout << "directmap access" << std::endl;
    //Write your code here
 
   //calculate number of bits of offset

	int offset_bits = log2(cache_line_size);
    
   //calculate number of bits of index

	
	int index_bits = log2(cache_size);
	
    //calculate number of bits of index
	
	int tag_bits = 48 - (offset_bits + index_bits);

	//Create Utils object	
	Utils utils;

	//Calculate offset value
	long offset = utils.extract_bits(full_address,offset_bits, 0);

	//Calculate index value
	long index = utils.extract_bits(full_address,index_bits, offset_bits);
	
	long added_bits = offset_bits + index_bits;
	//Calculate tag value	
	long tag = utils.extract_bits(full_address,tag_bits, added_bits);

	//int number_of_lines = cache_size / cache_line_size;
	//populating direct map
	//calculate tag
	


	
	cache[index % cache_size]->access(tag, mode);


	

	


	

	

    //check if the index exists in the map or not
    /*if (cache[index] != NULL) {
    	//hit
	std::cout << "before cache line access" << std::endl;
	cache[index]->access(full_address, mode);
    }
*/
}
void DirectMap::printStats (unsigned int crc,unsigned int cwc ,unsigned int mrc ,unsigned int mwc)
{
   //Write your code here
	int totalHits = 0;
	int totalMisses = 0;
	int totalCacheReads = 0; //mem read access attempts
	int totalCacheWrites = 0; //mem write access attempts
	int totalMEMReads = 0;
	int totalMEMWrites = 0;



	int counter = cache_size / cache_line_size;
	for (int i = 0; i < cache_size; i++){
		totalHits += cache[i]->getHits();
		totalMisses += cache[i]->getMisses();
		totalCacheReads += cache[i]->getCacheReads();
		totalCacheWrites += cache[i]->getCacheWrites();
		totalMEMReads += cache[i]->getMEMReads();
		totalMEMWrites += cache[i]->getMEMWrites();
	}

	std::cout << "totalHits: " << totalHits << std::endl;
	std::cout << "totalMisses: " << totalMisses << std::endl;
	std::cout << "totalCacheReads: " << totalCacheReads << std::endl;
	std::cout << "totalCacheWrites: " << totalCacheWrites << std::endl;
	std::cout << "totalMEMReads: " << totalMEMReads << std::endl;
	std::cout << "totalMEMWrites: " << totalMEMWrites << std::endl;

	std::cout << "Total Cache Read Cycles: " << totalCacheReads * crc << std::endl;
	std::cout << "Total Cache Write Cycles: " << totalCacheWrites * cwc << std::endl;
	std::cout << "Total Memroy Read Cycles: " << totalMEMReads * mrc << std::endl;
	std::cout << "Total Memory Wrtie Cycles: " << totalMEMWrites * mwc << std::endl;

	

}




DirectMap::~DirectMap()
{
    for ( uint16_t i = 0 ; i < cache_size; i++)
        delete (cache[i]);
}
