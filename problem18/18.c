/*
============================================================================
Name : 18.c
Author : Naman Samant
Description : 8. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
struct farm {
    int id;
    char data[100];
};
void createFarm(const char *fName) {
    	int fd = open(fName, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    	if (fd == -1) {
        	perror("Error opening file");
        	exit(1);
    	}
	struct farm farm[3] = {
        	{1, "Cow"},
        	{2, "Hens"},
        	{3, "Pigs"}
    	};
	for (int i = 0; i < 3; i++) {
        	if (write(fd, &farm[i], sizeof(struct farm)) == -1) {
            		perror("Error writing to file");
            		close(fd);
            		exit(1);
        	}
    	}
	close(fd);
}
void writeLock(int fd, off_t offset) {
    	struct flock lock;
    	lock.l_type = F_WRLCK;
    	lock.l_whence = SEEK_SET;
   	lock.l_start = offset;
   	lock.l_len = sizeof(struct farm);
   	lock.l_pid = getpid();
	if (fcntl(fd, F_SETLKW, &lock) == -1) {
        	perror("Error setting write lock");
        	exit(1);
    	}
}
void readLock(int fd, off_t offset) {
    	struct flock lock;
    	lock.l_type = F_RDLCK;
    	lock.l_whence = SEEK_SET;
    	lock.l_start = offset;
    	lock.l_len = sizeof(struct farm);
    	lock.l_pid = getpid();
	if (fcntl(fd, F_SETLKW, &lock) == -1) {
        	perror("Error setting read lock");
        	exit(1);
    	}
}
void unlock(int fd, off_t offset) {
    	struct flock lock;
    	lock.l_type = F_UNLCK;
    	lock.l_whence = SEEK_SET;
    	lock.l_start = offset;
    	lock.l_len = sizeof(struct farm);
    	lock.l_pid = getpid();
	if (fcntl(fd, F_SETLK, &lock) == -1) {
        	perror("Error unlocking");
        	exit(1);
    	}
}
void modifyFarm(const char *fName, int animalId, const char *newAnimal) {
    	int fd = open(fName, O_RDWR);
    	if (fd == -1) {
        	perror("Error opening file");
        	exit(1);
    	}
	off_t offset = (animalId - 1) * sizeof(struct farm);
    	writeLock(fd, offset);
	struct farm farm;
    	lseek(fd, offset, SEEK_SET);
    	if (read(fd, &farm, sizeof(struct farm)) == -1) {
        	perror("Error reading record");
        	close(fd);
        	exit(1);
    	}
	printf("Modifying Record %d: %s -> %s\n", farm.id, farm.data, newAnimal);
    	strcpy(farm.data, newAnimal);
	lseek(fd, offset, SEEK_SET);
    	if (write(fd, &farm, sizeof(struct farm)) == -1) {
        	perror("Error writing record");
        	close(fd);
        	exit(1);
    	}
	unlock(fd, offset);
	close(fd);
}
void read_farm(const char *fName, int animalId) {
	int fd = open(fName, O_RDONLY);
    	if (fd == -1) {
        	perror("Error opening file");
        	exit(1);
    	}
	off_t offset = (animalId - 1) * sizeof(struct farm);
    	readLock(fd, offset);
	struct farm farm;
    	lseek(fd, offset, SEEK_SET);
    	if (read(fd, &farm, sizeof(struct farm)) == -1) {
        	perror("Error reading record");
        	close(fd);
        	exit(1);
    	}
	printf("Read Record %d: %s\n", farm.id, farm.data);
	unlock(fd, offset);
	close(fd);
}
int main() {
    	const char *fName = "farm.dat";
	createFarm(fName);
	read_farm(fName, 2);
	modifyFarm(fName, 2, "Dog");
	read_farm(fName, 2);
	return 0;
}
