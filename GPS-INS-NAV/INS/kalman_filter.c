/*
 * kalman_filter.c
 *
 *  Created on: 12/1/17
 *      Author: Gur Chemel
 */

//#include "includes.h"
#include "kalman_filter.h"
#include "matrix_manipulation.h"

// Filtering the error between the INS and GPS for steady error correction.
void kalman_filter(double err_new[ERR_VEC_LENGTH], double err_old[ERR_VEC_LENGTH], double cov_mat[ERR_VEC_LENGTH][ERR_VEC_LENGTH], double noise_mat[ERR_VEC_LENGTH][ERR_VEC_LENGTH])
{
	int col,row;
	// Set err_new prediction:
	double err_predict[ERR_VEC_LENGTH];
	for (row=0;row<ERR_VEC_LENGTH;row++)
	{
		err_predict[row]=err_old[row];
	}

	// Set cov_mat prediction
	double cov_predict[ERR_VEC_LENGTH][ERR_VEC_LENGTH];
	for (row=0;row<ERR_VEC_LENGTH;row++)
	{
		for (col=0;col<ERR_VEC_LENGTH;col++)
		{
			cov_predict[row][col]=cov_mat[row][col];
		}
	}

	// Calculate Kalman-gain matrix.
	double temp_mat[3][3];
	double kalman_gain[3][3];
	matrix_add_3x3(cov_predict,noise_mat,temp_mat);
	matrix_inverse_3x3(temp_mat);
	matrix_product_3x3(cov_predict,temp_mat,kalman_gain);

	// Calculate err output.
	double temp_vec[ERR_VEC_LENGTH];
	for (row=0;row<ERR_VEC_LENGTH;row++)
	{
		temp_vec[row]=err_new[row]-err_predict[row];
	}
	for (row=0;row<ERR_VEC_LENGTH;row++)
	{
		err_old[row]=err_predict[row]+kalman_gain[row][0]*temp_vec[0]+kalman_gain[row][1]*temp_vec[1]+kalman_gain[row][2]*temp_vec[2];
	}

	// Calculate new cov_mat.
	double eye[3][3]={ {1,0,0}, {0,1,0}, {0,0,1} };
	matrix_sub_3x3(eye,kalman_gain,temp_mat);
	matrix_product_3x3(temp_mat,cov_predict,cov_mat);
}
