// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract EmployeeData {
    
    // Structure to hold employee data
    struct Employee {
        uint id;
        string name;
        uint age;
        string position;
        uint salary;
    }

    // Array to hold list of employees
    Employee[] public employees;
    uint public employeeCount = 0;

    // Function to add a new employee
    function addEmployee(string memory _name, uint _age, string memory _position, uint _salary) public {
        employeeCount++;
        employees.push(Employee(employeeCount, _name, _age, _position, _salary));
    }

    // Function to retrieve an employee by ID
    function getEmployee(uint _id) public view returns (uint, string memory, uint, string memory, uint) {
        require(_id > 0 && _id <= employeeCount, "Invalid Employee ID");
        Employee memory emp = employees[_id - 1];  // Array is 0-indexed
        return (emp.id, emp.name, emp.age, emp.position, emp.salary);
    }

    // Fallback function
    fallback() external payable {
        revert("This contract does not accept direct payments");
    }
    
    // Receive function (optional, if you want to receive Ether)
    receive() external payable {
        // If you want to accept Ether, you can implement this
    }
}
