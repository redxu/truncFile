# truncFile
Linux platform low level trunc(wipe) file.

# Features
* Pass though system cache
* Pass though Disk cache
* Support SATA Dom/IDE

Sometimes we trunc(delete) small file under linux and immediately reboot the system. The target file 
would be recover after reboot(cause of disk cache). So I use this way to wipe file.

