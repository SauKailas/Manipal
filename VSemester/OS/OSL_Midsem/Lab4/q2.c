#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

const char *perms(mode_t mode)
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
	int ret;

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	ret = stat(argv[1], &sb);

	if(ret == 1)
	{
		perror("Stat");
		exit(1);
	}

	printf("File: %s\n", argv[1]);
	printf("Inode: %ld\n", sb.st_ino);
	printf("Device Container ID: %ld\n", sb.st_dev);
	printf("Mode: %10.10s\n", perms(sb.st_mode));
	printf("Hard Links: %ld\n", sb.st_nlink);
	printf("User ID: %d\n", sb.st_uid);
	printf("Group ID: %d\n", sb.st_gid);
	printf("Device ID: %ld\n", sb.st_rdev);
	printf("Total Size: %ld\n", sb.st_size);
	printf("Block Size: %ld\n", sb.st_blksize);
	printf("Number of Blocks: %ld\n", sb.st_blocks);
	printf("Last Access Time: %s", ctime(&sb.st_atime));
	printf("Last Modified Time: %s", ctime(&sb.st_mtime));
	printf("Last Status: %s\n", ctime(&sb.st_ctime));

	return 0;
}