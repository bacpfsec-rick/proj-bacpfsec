/**
 * @file   State.cc
 * @Author Bacpfsec Rick
 * @date   20150324
 * @brief  Implementation of State Class
 *
 * State Class is used for Task Class
 */

#include "State.h"

State::State() : content(""), date(Date()) {

}

State::State(std::string s, const Date& dt) : content(s), date(dt) {

}

State::State(const State& st) {
  content = st.content;
  date = st.date;
}

State::~State() {

}

void State::setDate(const Date& dt) {
  date = dt;
}

Date State::getDate() {
  return date;
}

  /**    Setter for content
   *     @param s    A string for progress detail
   */ 
void State::setContent(std::string s) {
  content = s;
}

  /**    Getter for content
   *     @return      A string with details from private content
   */ 
std::string State::getContent() {
  return content;
}
