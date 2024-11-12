// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {

    // Structure to hold student data
    struct Student {
        uint id;
        string name;
        uint age;
        string course;
    }

    // Array to store multiple student structures
    Student[] public students;

    // Mapping to track student IDs to ensure uniqueness
    mapping(uint => bool) public studentExists;

    // Event to log student addition
    event StudentAdded(uint id, string name, uint age, string course);

    // Constructor marked as payable to accept Ether during deployment
    constructor() payable {
        // You can handle any Ether received during contract deployment here
    }

    // Fallback function to handle unexpected ETH sent to the contract
    fallback() external payable {
        // Handle ETH transfers or log a message
    }

    // Function to add a new student
    function addStudent(uint _id, string memory _name, uint _age, string memory _course) public {
        require(!studentExists[_id], "Student ID already exists.");
        students.push(Student(_id, _name, _age, _course));
        studentExists[_id] = true;

        // Emit event to log student addition
        emit StudentAdded(_id, _name, _age, _course);
    }

    // Function to get a student's details by index
    function getStudent(uint index) public view returns (uint, string memory, uint, string memory) {
        require(index < students.length, "Invalid index.");
        Student memory student = students[index];
        return (student.id, student.name, student.age, student.course);
    }

    // Function to get the total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    // Receive ETH into the contract
    receive() external payable {}

    // Function to withdraw any ETH sent to the contract
    function withdrawFunds() public {
        (bool success, ) = payable(msg.sender).call{value: address(this).balance}("");
        require(success, "Withdrawal failed.");
    }
}
