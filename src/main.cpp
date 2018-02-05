#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include <unordered_set>

#include "cgw-utils.h"
#include "cgw-uri.h"
#include "cgw-log.h"
#include "cgw-settings.h"
#include "json.hpp"

using json = nlohmann::json;

int main(void) {

  try {
    CGW::Settings = new CGW::settings();
  }
  catch(CGW::error_t& error) {
    printf("ERROR %s\n", error.get_text().c_str());
    exit(1);
  };

  std::vector<pthread_t> threads(CGW::Settings->threads);
  /*for(int i = 0; i < CGW::Settings->threads; i++)
      if(pthread_create(&threads[i], NULL, worker_builder, NULL)) {
          printf("Can't create thread\n");
          exit(1);
      } */
  printf("All %d threads created successfully.\n", CGW::Settings->threads);

  /*for(int i = 0; i < THREADS; i++)
      pthread_join(threads[i], NULL); */

  printf("All %d threads finishes their jobs.\n", CGW::Settings->threads); // */
  threads.clear();
  delete CGW::Settings;
  return 0;
}
