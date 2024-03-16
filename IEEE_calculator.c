#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

void calMode1(void);
void calMode2(void);
void calMode3(void);



float PtoRe(float, float);
float PtoIm(float, float);
float RtoMag(float, float);
float RtoAng(float, float);
float eff =  M_PI / 180.0;

int main() {
	while (1) {
		printf("--------------------------------------------------\n0. Terminate Program\n1. p <-> r\n2. p <-> p\n3. r <-> r\n");
		int cal_mode;
		scanf("%d", &cal_mode);
		getchar();
		if (cal_mode == 1) {
			calMode1();
		} else if (cal_mode == 2) {
			calMode2();
		} else if (cal_mode == 3) {
			calMode3();
		} else if (cal_mode == 0) {
			printf("\nTerminate Program");
			return 0;
		}
		getchar();
	}
}

float PtoRe(float mag, float ang) {
	float real_num = mag * cos(ang * eff);
	return real_num;
}

float PtoIm(float mag, float ang) {
	float im_num = mag * sin(ang * eff);
	return im_num;
}

float RtoMag(float real, float im) {
	float mag = sqrt(pow(real, 2) + pow(im, 2));
	return mag;
}

float RtoAng(float real, float im) {
	float ang = atan(im / real) / eff;
	return ang;
}

void calMode1(void) {
	char mode;
	printf("\nPolar -> Rectangular: p\nRectangular -> Polar: r\n");
	float mag, ang, real, im;
	scanf("%c", &mode);
	if (mode == 'p') {
		printf("\nMagnitude? ");
		scanf("%f", &mag);
		printf("\nAngle? ");
		scanf("%f", &ang);
		printf("\nresult = %.3f %+.3fj\n\n", PtoRe(mag, ang), PtoIm(mag, ang));
	} else if (mode == 'r') {
		printf("\nReal number? ");
		scanf("%f", &real);
		printf("\nImaginary number? ");
		scanf("%f", &im);
		printf("\nresult = %.3f <%.3f\n\n", RtoMag(real, im), RtoAng(real, im));
	}
}

void calMode2(void) {
	char cal_mode2;
	float first_mag, second_mag, first_ang, second_ang;
	float first_re, second_re, first_im, second_im;
	float res_mag, res_ang;
	printf("\nFirst Polar Magitude: ");
	scanf("%f", &first_mag);
	printf("\nFirst Polar Angle: ");
	scanf("%f", &first_ang);
	printf("\nSecond Polar Magitude: ");
	scanf("%f", &second_mag);
	printf("\nSecond Polar Angle: ");
	scanf("%f", &second_ang);
	printf("\nMultiply: m\nDivide: d\nAdd: a\nSubtract: s\n");
	getchar();
	scanf("%c", &cal_mode2);
	if (cal_mode2 == 'm') {
		printf("\nResult = %.2f <%.2f\n\n", first_mag * second_mag, first_ang + second_ang);
	} else if (cal_mode2 == 'd') {
		printf("\nResult = %.2f <%.2f\n\n", first_mag / second_mag, first_ang - second_ang);
	} else if (cal_mode2 == 'a') {
		first_re =  PtoRe(first_mag, first_ang);
		first_im =  PtoIm(first_mag, first_ang);
		second_re =  PtoRe(second_mag, second_ang);
		second_im =  PtoIm(second_mag, second_ang);
		res_mag = RtoMag(first_re + second_re, first_im + second_im);
		res_ang = RtoAng(first_re + second_re, first_im + second_im);
		printf("\nResult = %.2f <%.2f\n\n", res_mag, res_ang);
	} else if (cal_mode2 == 's') {
		first_re =  PtoRe(first_mag, first_ang);
		first_im =  PtoIm(first_mag, first_ang);
		second_re =  PtoRe(second_mag, second_ang);
		second_im =  PtoIm(second_mag, second_ang);
		res_mag = RtoMag(first_re - second_re, first_im - second_im);
		res_ang = RtoAng(first_re - second_re, first_im - second_im);
		printf("\nResult = %.2f <%.2f\n\n", res_mag, res_ang);		
	}
}

void calMode3(void) {
	char cal_mode3;
	float first_mag, second_mag, first_ang, second_ang;
	float first_re, second_re, first_im, second_im;
	float res_mag, res_ang;
	printf("\nFirst Real Number: ");
	scanf("%f", &first_re);
	printf("\nFirst Imaginary Number: ");
	scanf("%f", &first_im);
	printf("\nSecond Real Number: ");
	scanf("%f", &second_re);
	printf("\nSecond Imaginary Number: ");
	scanf("%f", &second_im);
	printf("\nMultiply: m\nDivide: d\nAdd: a\nSubtract: s\n");
	getchar();
	scanf("%c", &cal_mode3);
	if (cal_mode3 == 'a') {
		printf("\nResult = %.2f %+.2fj\n\n", first_re + second_re, first_im + second_im);
	} else if (cal_mode3 == 's') {
		printf("\nResult = %.2f %+.2fj\n\n", first_re - second_re, first_im - second_im);
	} else if (cal_mode3 == 'm') {
		first_mag = RtoMag(first_re, first_im);
		first_ang = RtoAng(first_re, first_im);
		second_mag = RtoMag(second_re, second_im);
		second_ang = RtoAng(second_re, second_im);
		res_mag = first_mag * second_mag;
		res_ang = first_ang + second_ang;
		printf("\nResult = %.2f %+.2fj\n\n", PtoRe(res_mag, res_ang), PtoIm(res_mag, res_ang));
	} else if (cal_mode3 == 'd') {
		first_mag = RtoMag(first_re, first_im);
		first_ang = RtoAng(first_re, first_im);
		second_mag = RtoMag(second_re, second_im);
		second_ang = RtoAng(second_re, second_im);
		res_mag = first_mag / second_mag;
		res_ang = first_ang - second_ang;
		printf("\nResult = %.2f %+.2fj\n\n", PtoRe(res_mag, res_ang), PtoIm(res_mag, res_ang));
	}
}

