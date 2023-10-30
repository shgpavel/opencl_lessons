#include <CL/cl.h>
#include <stdio.h>

int main(void) {
    cl_uint numPlatforms;
    clGetPlatformIDs(0, NULL, &numPlatforms);

    cl_platform_id* platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
    clGetPlatformIDs(numPlatforms, platforms, NULL);
    
    for (cl_uint i = 0; i < numPlatforms; i++) {
        printf("Platform %d:\n", i + 1);

        char platformName[128];
        clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(platformName), platformName, NULL);
        printf("  Name: %s\n", platformName);

        cl_uint numDevices;
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);

        cl_device_id* devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);

        for (cl_uint j = 0; j < numDevices; j++) {
            printf("  Device %d:\n", j + 1);
            char deviceName[128];
            clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL);
            printf("    Name: %s\n", deviceName);
        }

        free(devices);
    }

    free(platforms);

    return 0;
}
