#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  cl_uint numPlatforms;
  cl_int err = clGetPlatformIDs(0, NULL, &numPlatforms);
  if (err != CL_SUCCESS) {
    fprintf(stderr, "Error: Could not get OpenCL platform count\n");
    return 1;
  }
  
  cl_platform_id *platforms =
      (cl_platform_id *)malloc(numPlatforms * sizeof(cl_platform_id));
  err = clGetPlatformIDs(numPlatforms, platforms, NULL);
  if (err != CL_SUCCESS) {
    fprintf(stderr, "Error: Could not get OpenCL platforms\n");
    return 1;
  }
  
  for (cl_uint i = 0; i < numPlatforms; ++i) {
    printf("Platform %d ", i + 1);

    char platformName[128];
    clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(platformName),
                      platformName, NULL);
    printf("%s\n", platformName);

    cl_uint numDevices;
    err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    if (err != CL_SUCCESS) {
      fprintf(stderr, "Error: Could not get OpenCL devices count\n");
      continue;
    }
    
    cl_device_id *devices =
        (cl_device_id *)malloc(numDevices * sizeof(cl_device_id));
    err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);
    if (err != CL_SUCCESS) {
      fprintf(stderr, "Error: Could not get OpenCL platform devices\n");
      continue;
    }
    
    for (cl_uint j = 0; j < numDevices; ++j) {
      printf("\tDevice %d ", j + 1);
      char deviceName[128];
      err = clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(deviceName),
                      deviceName, NULL);
      if (err != CL_SUCCESS) { 
        fprintf(stderr, "Error: Could not get OpenCL device info\n");
        continue;
      }
      printf("%s\n", deviceName);
    }

    free(devices);
  }
  free(platforms);

  return 0;
}
