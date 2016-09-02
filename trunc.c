/*****************************************************************************
* 文件描述：truncFile
* 应用平台：linux
* 创建时间：20160902
* 作者：RedXu
*****************************************************************************/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * trunc file
 * @param  filename [filename]
 * @return          [0:success other:error]
 */
int truncFile(const char* filename)
{
	int rtv;
	int fd;
	int flags = O_WRONLY | O_TRUNC | O_NOFOLLOW | O_SYNC | O_DIRECT;
	int pagesize;
	unsigned char* alignbuf;

	if((fd = open(filename, flags)) < 0)
	{
		//文件不存在
		if(errno == 2)
			return 0;
		printf("FILE: %s LINE: %d -- Open file Failed! path=[%s]\n", __FILE__, __LINE__, filename);
		return(-1);
	}
	pagesize = getpagesize();
	//写内存对齐
	rtv = posix_memalign((void **)&alignbuf, pagesize, pagesize);
	if(rtv)
	{
		printf("FILE: %s LINE: %d -- Mem align Failed!\n", __FILE__, __LINE__);
		close(fd);
		return(-2);
	}
	//填充0
	memset(alignbuf, 0, pagesize);
	if(write(fd, alignbuf, pagesize) != pagesize)
	{
		printf("FILE: %s LINE: %d -- Erase file Failed! path=[%s]\n", __FILE__, __LINE__, filename);
		free(alignbuf);
		close(fd);
		return(-3);
	}
	free(alignbuf);
	ftruncate(fd, 0);
	lseek(fd, 0, SEEK_SET);
	fdatasync(fd);
	fsync(fd);
	close(fd);
	return 0;
}
