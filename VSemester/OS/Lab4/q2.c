#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

const char *perms(__mode_t mode)
{
	static char buf[16] = {0};
	int i = 0;

	// User permissions
	buf[i++] = ((mode & S_IRUSR) ? 'r' : '-');
	buf[i++] = ((mode & S_IWUSR) ? 'w' : '-');
	buf[i++] = ((mode & S_IXUSR) ? 'x' : '-');

	// Group permissions
	buf[i++] = ((mode & S_IRGRP) ? 'r' : '-');
	buf[i++] = ((mode & S_IWGRP) ? 'w' : '-');
	buf[i++] = ((mode & S_IXGRP) ? 'x' : '-');

	// Other permissions
	buf[i++] = ((mode & S_IROTH) ? 'r' : '-');
	buf[i++] = ((mode & S_IWOTH) ? 'w' : '-');
	buf[i++] = ((mode & S_IXOTH) ? 'x' : '-');

	return buf;
}


int main(int argc, char *argv[])
{
	struct stat sb;

	if(argc < 2)
	{
		printf("Filename not provided!\n");
		return 1;
	}

	int ret = stat(argv[1], &sb);

	if(ret)
	{
		perror("stat");
		return 1;
	}

	printf("File: %s \nInode: %ld \nDevice Container ID: %ld \nMode: %10.10s \nHard Links: %ld \nUser ID: %d \nGroup ID: %d \nDevice ID: %ld \nTotal Size: %ld \nBlock Size: %ld \nNumber of blocks: %ld \nLast Access Time: %sLast Modified: %sLast Status: %s", 
			argv[1], 
			sb.st_ino, 
			sb.st_dev, 
			perms(sb.st_mode), 
			sb.st_nlink, 
			sb.st_uid, 
			sb.st_gid, 
			sb.st_rdev, 
			sb.st_size, 
			sb.st_blksize, 
			sb.st_blocks, 
			ctime(&sb.st_atime), 
			ctime(&sb.st_mtime), 
			ctime(&sb.st_ctime));

	return 0;
}