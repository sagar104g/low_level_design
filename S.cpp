/*
Single Responsibility Principle
    single class should not handle everything
    A class should have a single responsibility
*/
class Task {
    public:
         void downloadFile();
         void parseTheFile();
         void persistTheData();
};
