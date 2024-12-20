/* Given an integer array nums, return true if any value appears at least twice in the array, 
 * and return false if every element is distinct.
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/* 
 *Solution 1:  Using UTHASH. This needs the header file uthash.h 
 */
/*#include"./uthash.h"

typedef struct {
	int key;
	UT_hash_handle hh; //makes this struct hashable
}hash_table;

//now define hash table variable
hash_table *table=NULL, *elem, *tmp; 

bool contains_dup(int *nums, size_t numsize)
{
	if(numsize==1)
		return false;

	bool flag =false;
	for(int i =0;i<numsize;i++) {
		HASH_FIND_INT(table,&nums[i],elem);
		if(!elem) {
			elem = malloc(sizeof(hash_table));
			elem->key = nums[i];
			HASH_ADD_INT(table,key,elem);
			
			flag = false;
		}
		else {
			flag = true;
			break;
		}
	}
	
	//free up hash table
	HASH_ITER(hh,table,elem,tmp) {
		HASH_DEL(table,elem);
		free(elem);	
	}	
	return flag;
}
*/

/*
 * Solution 2:Using simple hash technique of static array 
 */
/*#define SIZE 20

int hashArray[SIZE]={0};

int hashCode(int item)
{
        return item % SIZE;
}

bool contains_dup(int* nums, int numsSize){
    int i = 0, code = 0;

        bool flag = false;
        //get each of the elements from the input array 
        for(i=0; i<numsSize; i++) {
                //get the hash
                code =hashCode(nums[i]);
                //check if empty or already there
                if(hashArray[code] == 0)
                        hashArray[code] = nums[i];
                else 
                        flag = true;

        }
        return flag;
}*/

/*
 * Solution 3: Using hashset
 */

typedef struct {
	bool *set;
}Myhashset;

Myhashset *hashsetcreate()
{
	Myhashset *obj = (Myhashset *)malloc(sizeof(Myhashset));
	obj->set = (bool *)malloc(100 *sizeof(bool));

	return obj;
}
void Myhashsetadd(Myhashset *obj, int key)
{
	obj->set[key] = true;
}

bool MyhashsetContains(Myhashset *obj, int key)
{
	return obj->set[key];
}

bool contains_dup_hashset(int* nums, int numsSize, Myhashset *obj)
{
	for(int i=0;i<numsSize;i++) {
		if(MyhashsetContains(obj,nums[i]))
			return true;
		else
			Myhashsetadd(obj, nums[i]);
	}
	return false;
}

int main()
{
	int nums[]={1,2,3,4,5};
	//Solution 3
	Myhashset *obj = hashsetcreate();

	bool ret = contains_dup_hashset(nums,sizeof(nums)/sizeof(int),obj);
	//bool ret = contains_dup(nums,sizeof(nums)/sizeof(int));

	if(ret)
		printf("duplicate element is present\n");
	else
		printf("no duplicate\n");

	return 0;
}
