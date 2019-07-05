#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

class Process: public std::enable_shared_from_this<Process> {
 public:
  explicit Process(const std::string& name): name_{name} {
    std::cout << "Process " << name << " is being created\n";
  }

  Process(const Process&) = delete;
  Process(Process&&) = delete;
  Process& operator=(const Process&) = delete;
  Process& operator=(Process&&) = delete;

  ~Process() {
    std::cout << "Process " << name_ << " is being killed\n";
    for (const auto& listener : blocking_) {
      if (auto sp = listener.lock()) {
        std::cout << "  Process " << sp->name_ << " is no longer blocked on " << name_ << '\n';
      }
    }
    std::cout << "Process " << name_ << " is killed\n";
  }

  void Wait(const Process& other) {
    other.blocking_.push_back(weak_from_this());
    std::cout << "  Process " << name_ << " now blocked on " << other.name_ << '\n';
  }

 private:
  // We make this mutable as it's unrelated to the state of this process.
  mutable std::vector<std::weak_ptr<Process>> blocking_;
  std::string name_;
};

int main() {
  std::cout << "\nNo waiting\n";
  {
    std::make_shared<Process>("simpleprocess");
  }

  std::cout << "\nWaiting on a process (normal case)\n";
  {
    auto parent = std::make_shared<Process>("parent");
    auto child = std::make_shared<Process>("childkilledfirst");
    parent->Wait(*child);
  }

  std::cout << "\nWaiting on a process, but the thing waiting gets killed\n";
  {
    auto parent = std::make_shared<Process>("parentkilledfirst");
    auto child = std::make_shared<Process>("child");
    parent->Wait(*child);
    parent = nullptr;
  }
}
