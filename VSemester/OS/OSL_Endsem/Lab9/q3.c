#include<stdio.h>
#include<stdlib.h>

struct SegmentEntry
{
	int base;
	int limit;
}SegmentTable[5];

void InitialiseSegmentTable()
{
	SegmentTable[0].base = 0;
	SegmentTable[0].limit = 255;
	SegmentTable[1].base = 256;
	SegmentTable[1].limit = 511;
	SegmentTable[2].base = 512;
	SegmentTable[2].limit = 767;
	SegmentTable[3].base = 768;
	SegmentTable[3].limit = 1023;
	SegmentTable[4].base = 1024;
	SegmentTable[4].limit = 1279;
}

int getPhysicalAddress(int segment, int offset)
{
	if(segment < 0 || segment > 4 || offset < 0)
		return -1;
	else if(offset > SegmentTable[segment].limit)
		return -1;
	else
	{
		int physicalAddress = SegmentTable[segment].base + offset;
		return physicalAddress;
	}
}

int main()
{
	InitialiseSegmentTable();

	int logicalAddress1 = 53;
	int segment1 = 2;
	int physicalAddress1 = getPhysicalAddress(segment1, logicalAddress1);
	if(physicalAddress1 == -1)
		printf("Invalid Logical Address!\n");
	else
		printf("Physical Address for %d bytes of segment %d is %d!\n", logicalAddress1, segment1, physicalAddress1);

	int logicalAddress2 = 852;
	int segment2 = 3;
	int physicalAddress2 = getPhysicalAddress(segment2, logicalAddress2);
	if(physicalAddress2 == -1)
		printf("Invalid Logical Address!\n");
	else
		printf("Physical Address for %d bytes of segment %d is %d!\n", logicalAddress2, segment2, physicalAddress2);

	int logicalAddress3 = 1222;
	int segment3 = 0;
	int physicalAddress3 = getPhysicalAddress(segment3, logicalAddress3);
	if(physicalAddress3 == -1)
		printf("Invalid Logical Address!\n");
	else
		printf("Physical Address for %d bytes of segment %d is %d!\n", logicalAddress3, segment3, physicalAddress3);

	return 0;
}