/**
 * @file   MenuDetail.cc
 * @Author Bacpfsec Rick
 * @date   20150416
 * @brief  Implementation of MenuSimple Class
 *
 * MenuSimple is literally a simple hello to the user
 */
#include "MenuDetail.h"

void MenuDetail::welcome(std::ostream& os) {
  os<<"**************************************"<<std::endl;
  os<<"**************************************"<<std::endl;
  os<<"**                                  **"<<std::endl;
  os<<"**        Welcome to BacpFseC       **"<<std::endl;
  os<<"**                                  **"<<std::endl;
  os<<"** -------------------------------- **"<<std::endl;
  os<<"** |     Philosophy of BacfFseC   | **"<<std::endl;
  os<<"** |         B : Balanced         | **"<<std::endl;
  os<<"** |        A : Accelerated       | **"<<std::endl;
  os<<"** |         C : Creative         | **"<<std::endl;
  os<<"** |         P : Parallel         | **"<<std::endl;
  os<<"** |        Fs : Full-stack       | **"<<std::endl;
  os<<"** |        E : Engineering       | **"<<std::endl;
  os<<"** |         C : Conqueror        | **"<<std::endl;
  os<<"** -------------------------------- **"<<std::endl;
  os<<"**                                  **"<<std::endl;
  os<<"** -------------------------------- **"<<std::endl;
  os<<"** | With BacFseC, you can track: | **"<<std::endl;
  os<<"** |  - number of task in effect  | **"<<std::endl;
  os<<"** |  - number of task completed  | **"<<std::endl;
  os<<"** |  - number of task cancelled  | **"<<std::endl;
  os<<"** |  - status for specific task  | **"<<std::endl;
  os<<"** |  - efficiency within period  | **"<<std::endl;
  os<<"** -------------------------------- **"<<std::endl;
  os<<"**                                  **"<<std::endl;
  os<<"**************************************"<<std::endl;
  os<<"**************************************"<<std::endl;
}
