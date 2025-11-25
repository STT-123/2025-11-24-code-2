#include "ocpp_task.h"
#include "device_drv/ocpp_protocol/ocpp/ws_client.h"
#include "interface/log/log.h"

pthread_t ws_thread = 0;

void ocppCommunicationTaskCreate(void)
{
    int ret;
    do {
        ret = pthread_create(&ws_thread, NULL, ocppCommunicationTask, NULL);
        if (ret != 0) {
            LOG("[Ocpp] Failed to create ocppCommunicationTask : %s",strerror(ret));
            sleep(1); 
        }
        else
        {
            LOG("[Ocpp] ocppCommunicationTask created successfully.\r\n");
        }
    } while (ret != 0);
}