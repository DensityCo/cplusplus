/*This application demonstrates how to implement
 * the GoF statemachine design pattern.*/

#include <iostream>
#include <functional>
#include <string>
#include <vector>
namespace
{

    /*Forward declare lockbox so that the lockbox_state class
     * can access the protected lockbox API.  lockbox_state and
     * lockbox are intentionally tightly coupled.
     */
    class lockbox;

    /**
     * @brief The lockbox_state class is an Abstract Base Class for
     * all lockbox states.  It provides the interface that allows subclasses
     * to act on events that will drive the statemachine.
     */
    class lockbox_state
    {

        lockbox& m_lockbox;

        std::string m_name;

    protected:

        lockbox_state(lockbox& _lockbox, const std::string& name)
            : m_lockbox(_lockbox),
              m_name(name)
        {}

        const std::string& name()
        {
            return m_name;
        }

        /*The implementation of these methods require dereferencing
         * the lockbox reference.  Therefore, they must be defined
         * after the lockbox class has been defined.  Note the difference
         * between "declaration" and "definition" of a class.
         */
        void transition_to_norobot_state();
        void transition_to_display_state();
        void transition_to_password_state();
        void display_secret();
    public:

        virtual void enter_state()
        {
            std::cerr << "Entering state: " << m_name << std::endl;
        }

        virtual void exit_state()
        {
            std::cerr << "Exiting state: " << m_name << std::endl;
        }

        virtual void watchdog_timeout()
        {
           transition_to_norobot_state();
        }

        virtual void backdoor_signal()
        {
            transition_to_display_state();
        }

        virtual void keyboard_input(const std::string& line) = 0;

        virtual ~lockbox_state()
        {}
    };

    /*Could be named initial state but name null so it relates to the
     * null object design pattern.
     */
    class null_state : public lockbox_state
    {
    public:

        null_state(lockbox& _lockbox)
            : lockbox_state(_lockbox, "null")
        {}

        void enter_state() override
        {}

        void exit_state() override
        {}

        void watchdog_timeout() override
        {}

        void backdoor_signal() override
        {}

        void keyboard_input(const std::string& line) override
        {}
    };

    /**
     * @brief The no_robot_state class Implements a challenget that requires the
     * user to input the 'Density is awesome' string.
     */
    class no_robot_state : public lockbox_state
    {
    public:

        no_robot_state(lockbox& _lockbox)
            : lockbox_state(_lockbox, "no_robot")
        {

        }

        void enter_state() override
        {
            lockbox_state::enter_state();
            std::cerr << "Please input the following text to prove you are not a robot: 'Density is awesome'" << std::endl;
        }

        void watchdog_timeout() override
        {}

        void keyboard_input(const std::string& line) override
        {
            if(line == "Density is awesome")
            {
                std::cerr << "No robot text accepted.. moving on to next challenge" << std::endl;
                transition_to_password_state();
            }
            else
            {
                std::cerr << "No robot text not accepted.  Try again..." << std::endl;
            }
        }
    };

    /**
     * @brief The password_state class Implements the password challenge, where the user
     * has 3 attempts to implement the correct password.
     */
    class password_state : public lockbox_state
    {
        static const int MAX_ATTEMPTS = 3;

        int m_attempts;
        std::string m_password;
    public:

        password_state(lockbox& _lockbox, const std::string& initial_password)
            : lockbox_state(_lockbox, "password"),
              m_attempts(0),
              m_password(initial_password)
        {}

        void set_password(const std::string& new_password)
        {
            m_password = new_password;
        }

        void enter_state() override
        {
            //Call the parent class implementation
            lockbox_state::enter_state();

            std::cerr << "Enter the password" << std::endl;
        }

        void exit_state() override
        {
            lockbox_state::exit_state();
            m_attempts = 0;
        }

        void keyboard_input(const std::string& line) override
        {
            if(line == m_password)
            {
                std::cerr << "Password accepted" << std::endl;
                transition_to_display_state();
            }
            else
            {
                ++m_attempts;
                if(m_attempts == MAX_ATTEMPTS)
                {
                    std::cerr << "Maximum number of attempts exceeded" << std::endl;
                    transition_to_norobot_state();
                }
                else
                {
                    std::cerr << "Enter password (Failed attempts: " << m_attempts << "/" << MAX_ATTEMPTS << ")" << std::endl;
                }
            }
        }
    };

    /**
     * @brief The display_state class implements displaying of the lock box's secret.
     * After displaying the secret, the user can press any key to go back to the
     * no_robot state.
     */
    class display_state : public lockbox_state
    {
    public:
        display_state(lockbox& _lockbox)
            : lockbox_state(_lockbox, "null")
        {}

        void enter_state() override
        {
            //Call the parent class implementation
            lockbox_state::enter_state();

            display_secret();
        }

        void exit_state() override
        {
            std::cerr << "Secret has been displayed" << std::endl;
            lockbox_state::exit_state();
        }

        void watchdog_timeout() override
        {}

        void backdoor_signal() override
        {}

        void keyboard_input(const std::string& line) override
        {
            transition_to_norobot_state();
        }
    };

    /**
     * @brief The lockbox class Is the implementation of the lockbox including the public API.
     */
    class lockbox
    {
        std::vector<char> m_secret; /**< The secret we are hiding*/

        /*An instantiation of each state.  With some statemachines it makes sense
         * to maintain a cache of states like this.  Other statemachines it makes
         * sense to instantiate/destroy the state object on state transition.*/
        null_state m_initial_state;
        no_robot_state m_no_robot_state;
        password_state m_password_state;
        display_state m_display_state;

        lockbox_state* m_current_state; /**< A pointer to the current state.  In my opinion
                                          * this is one of the only situations where a raw pointer should
                                          * be used.  The pointer is used to point to one of various
                                          * objects and it can be updated.  The objects it points to
                                          * should not be 'owned' by this pointer.  i.e. you should never
                                          * need to call delete on this raw pointer.
                                          */

        /*Allow the lockbox_state class to access the private and protected
         * members of this class*/
        friend class lockbox_state;

        void transition_state(lockbox_state& next_state)
        {
             m_current_state->exit_state();
             m_current_state = &next_state;
             m_current_state->enter_state();
        }

        void display_secret()
        {
             std::cerr << "Lockbox unlocked!!!" << std::endl;
             std::cout << "Secret: " << std::string(m_secret.begin(), m_secret.end()) << std::endl;

             m_secret.clear();
        }

    public:

        lockbox()
            : m_secret(),
              m_initial_state(*this),
              m_no_robot_state(*this),
              m_password_state(*this, ""),
              m_display_state(*this),
              m_current_state(&m_initial_state)
        {}

        void lock(const std::string& secret, const std::string& password)
        {
            m_secret = std::vector<char>(secret.begin(), secret.end());
            m_password_state.set_password(password);
        }

        void unlock()
        {
            if(m_secret.empty())
            {
                return;
            }

            transition_state(m_no_robot_state);
        }

        void keyboard_input(const std::string& line)
        {
            m_current_state->keyboard_input(line);
        }

    };

    /*Implementation of lockbox_state methods that need access to
     * the m_lockbox reference.  The compiler now allows it because
     * the lockbox class has been defined.
     */
    void lockbox_state::transition_to_norobot_state()
    {
         m_lockbox.transition_state(m_lockbox.m_no_robot_state);
    }

    void lockbox_state::transition_to_display_state()
    {
        m_lockbox.transition_state(m_lockbox.m_display_state);
    }

    void lockbox_state::transition_to_password_state()
    {
        m_lockbox.transition_state(m_lockbox.m_password_state);
    }

    void lockbox_state::display_secret()
    {
        m_lockbox.display_secret();
    }
}

int main(int argc, char** argv)
{
    /*Create the lockbox*/
    lockbox box;

    /*Lock a secret with a password*/
    box.lock("my super secret nobody should know", "mypass");

    /*Attempt to access the secret*/
    box.unlock();

    while(true)
    {
        /*Get a line from stdin*/
        std::string line;
        std::getline(std::cin, line);

        /*Drive the lockbox unlock state machine.*/
        box.keyboard_input(line);
    }
}
