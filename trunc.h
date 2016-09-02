/*****************************************************************************
* 文件描述：truncFile
* 应用平台：linux
* 创建时间：20160902
* 作者：RedXu
*****************************************************************************/

#ifndef __TRUNCFILE__H__
#define __TRUNCFILE__H__

#ifdef __cplusplus
extern "C" {
#endif


/**
 * trunc file
 * @param  filename [filename]
 * @return          [0:success other:error]
 */
int truncFile(const char* filename);


#ifdef __cplusplus
}
#endif


#endif
