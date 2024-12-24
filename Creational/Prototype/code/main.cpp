#include <iostream>
#include "ConcretePrototype.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    ConcretePrototype* prototype = new ConcretePrototype("Example");
    ConcretePrototype* clonedPrototype = dynamic_cast<ConcretePrototype*>(prototype->clone());

    std::cout << "Original object data: " << prototype->getData() << std::endl;
    std::cout << "Cloned object data: " << clonedPrototype->getData() << std::endl;

    delete prototype;
    delete clonedPrototype;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.