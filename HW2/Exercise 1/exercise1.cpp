#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>



using namespace boost::interprocess;

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        // delete SHM if exists
        shared_memory_object::remove("MySharedMemory");
        
        //Construct managed shared memory
        managed_shared_memory segment(create_only, "MySharedMemory", 65536);

        //Create an object of MyType initialized to an int
        int integer;
        std::cout << "Input an int into the shared memory" << std::endl;
        std::cin >> integer;
        
        int *instance = segment.construct<int>
            ("Int instance")  //name of the object
            (integer);            //ctor first argument

                                    
        std::cout <<"In main program, the int in the shared memory is: "<< integer<< std::endl;

        // run child program
        main(0, 0);
        
        //delete all the objects
		segment.destroy<int>("Int instance");

    }else{
		//Open managed shared memory
		managed_shared_memory segment(open_only, "MySharedMemory");

		std::pair<int*, managed_shared_memory::size_type> res;

		//Find the array
		res = segment.find<int>("Int instance");
		std::cout << "In child program, the int in shard memory is: "<<*res.first << std::endl;
		

    }

}