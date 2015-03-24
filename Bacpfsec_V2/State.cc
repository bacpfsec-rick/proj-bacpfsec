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

void State::setContent(std::string s) {
  content = s;
}

std::string State::getContent() {
  return content;
}

void State::merge(std::string s) {
  content += (" + " + s);
}
