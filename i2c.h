/*
 * i2c.h
 *
 *  Created on: Jan 29, 2015
 *      Author: xiaoqing
 */

#ifndef I2C_H_
#define I2C_H_


#define I2C_OK                0
#define I2C_ERROR             1

int open_i2c(const char* dev_path, unsigned char addr);
void close_i2c(int dev);
int set_i2c_data(int dev, unsigned char val);
int get_i2c_data(int dev, unsigned char *value);



#endif /* I2C_H_ */
