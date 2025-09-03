#include "Canvas.h"
#include "Caretaker.h"
#include "ExportCanvas.h"
#include "Memento.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
#include "Rectangle.h"
#include "RectangleFactory.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "Square.h"
#include "SquareFactory.h"
#include "Textbox.h"
#include "TextboxFactory.h"

int main()
{
    //                                                         SECTION 1:FACTORIES
    // =====================================================================================================================================================================
    std::cout << std::endl
              << "SECTION 1: FACTORIES" << std::endl;
    //******************************************************************************************************************************************************************* */

    std::cout << "SECTION 1.1: RECTANGLE FACTORY" << std::endl;

    std::cout << "Creating Rectangle Factory..." << std::endl;
    RectangleFactory *recFactory = new RectangleFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a rectangle using rectangle factory..." << std::endl;
    Shape *rec = recFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *rec_clone = rec->clone();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 1.2: SQUARE FACTORY" << std::endl;

    std::cout << "Creating Square Factory..." << std::endl;
    SquareFactory *squareFactory = new SquareFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a square using square factory..." << std::endl;
    Shape *square = squareFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *sqr_clone = square->clone();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 1.3: TEXTBOX FACTORY" << std::endl;

    std::cout << "Creating Textbox Factory..." << std::endl;
    TextboxFactory *txtboxFactory = new TextboxFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a textbox using textbox factory..." << std::endl;
    Shape *txt = txtboxFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *txt_clone = txt->clone();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "SECTION 1: FACTORIES SUCCESSFUL" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 1.4: ADDITIONAL TESTING" << std::endl;
    Rectangle *test_rec = new Rectangle();
    test_rec->changeLength(-1);
    test_rec->changeWidth(-1);
    test_rec->changeColour("Blue");
    test_rec->changeLength(8);
    test_rec->changePosition(4, 4);
    test_rec->changeWidth(1);
    test_rec->toString();
    Shape *test_rec1 = test_rec->clone();

    delete test_rec1;
    if (test_rec != nullptr)
    {
        delete test_rec;
    }

    Square *test_square = new Square();
    test_square->changeLength(-1);
    test_square->changeWidth(-1);
    test_square->changeLength(8);
    test_square->changePosition(5, 5);
    test_square->changeWidth(8);
    test_square->toString();
    Shape *test_square1 = test_square->clone();

    delete test_square1;
    if (test_square != nullptr)
    {
        delete test_square;
    }

    //                                                              SECTION 2:CANVAS
    // =====================================================================================================================================================================
    std::cout << "SECTION 2: CANVAS" << std::endl;
    std::cout << "SECTION 2.1: CREATE CANVAS, ADD/STORE A GREEN RECTANGLE" << std::endl;

    std::cout << "Creating canvas..." << std::endl;
    Canvas *mspaint = new Canvas();
    Caretaker *ct = new Caretaker();
    mspaint->contains();
    mspaint->captureCurrent();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Testing Case: Empty prev/post..." << std::endl;
    mspaint->undoAction();
    std::cout << "Successful undo..." << std::endl;

    mspaint->redoAction();
    std::cout << "Successful redo..." << std::endl;
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing colour of rectangle to green..." << std::endl;
    rec->changeColour("Green");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of rectangle..." << std::endl;
    rec->changeLength(6);
    rec->changeWidth(3);
    mspaint->contains();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of rectangle..." << std::endl;
    rec->changePosition(12, 23);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding rectangle to canvas..." << std::endl;
    mspaint->addToCanvas(rec);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Printing rectangle..." << std::endl;
    rec->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.2: ADD/STORE A RED SQUARE" << std::endl;

    std::cout << "Changing colour of square to red..." << std::endl;
    square->changeColour("Red");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of square..." << std::endl;
    square->changeLength(9);
    square->changeWidth(9);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of square..." << std::endl;
    square->changePosition(11, 13);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding square to canvas..." << std::endl;
    mspaint->addToCanvas(square);
    mspaint->addToCanvas(nullptr);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Printing square..." << std::endl;
    square->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.3: ADD/STORE A WHITE TEXTBOX" << std::endl;

    std::cout << "Changing colour of textbox to white..." << std::endl;
    txt->changeColour("White");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of textbox..." << std::endl;
    txt->changeLength(10);
    txt->changeWidth(3);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of textbox..." << std::endl;
    txt->changePosition(11, 13);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding square to canvas..." << std::endl;
    mspaint->addToCanvas(square);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Setting text of textbox..." << std::endl;
    TextBox *txt_test = new TextBox();
    txt_test->changeColour("White");
    txt_test->changeLength(-1);
    txt_test->changeWidth(-1);
    txt_test->setText("Hello World");
    txt_test->changePosition(11, 13);
    txt_test->changeLength(10);
    /**********************************************************************************************************************************************************************/
    std::cout << "SECTION 2.4: ADDITIONAL TESTING" << std::endl;
    txt_test->changeWidth(3);

    std::cout << "Printing textbox..." << std::endl;
    txt_test->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.4: UNDO" << std::endl;
    std::cout << "Performing an AddToCanvas() for undo test..." << std::endl;

    Shape *square_undo = square->clone();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding to canvas..." << std::endl;
    mspaint->addToCanvas(square_undo);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting undo..." << std::endl;
    mspaint->undoAction();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.5: REDO" << std::endl;

    std::cout << "Attempting redo..." << std::endl;
    mspaint->redoAction();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.6: ADDITIONAL TESTING" << std::endl;

    std::cout << "Performing additional tests..." << std::endl;
    Canvas *extra = new Canvas();
    Memento *temp_mem = new Memento(nullptr);
    if (temp_mem != nullptr)
    {
        delete temp_mem;
    }
    extra->removeFromCanvas();
    extra->contains();
    extra->addShape("Square");
    extra->changeColour("Green");
    extra->changeLength(3);
    extra->changeWidth(2);
    extra->changePosition(3, 3);
    ct->add(extra->captureCurrent());
    
    extra->clearCanvas();

    extra->addShape("Textbox");
    extra->changeColour("Green");
    extra->changeLength(3);
    extra->changeWidth(2);
    extra->changePosition(3, 3);
    ct->add(extra->captureCurrent());
    extra->clearCanvas();

    extra->addShape("Rectangle");
    extra->changeColour("Green");
    extra->changeLength(3);
    extra->changeWidth(2);
    extra->changePosition(3, 3);
    ct->add(extra->captureCurrent());
    extra->contains();

    ct->continueAction();

    Memento *test_mem = extra->captureCurrent();
    extra->removeFromCanvas();
    delete extra;
    delete ct;

    if (test_mem != nullptr)
    {
        delete test_mem;
    }

    ShapeFactory *s1 = new RectangleFactory();
    ShapeFactory *s2 = new SquareFactory();
    ShapeFactory *s3 = new TextboxFactory();

    delete s1;
    delete s2;
    delete s3;

    Shape *_rec = new Rectangle();
    Shape *_sqr = new Square();
    Shape *_txt = new TextBox();

    delete _rec;
    delete _sqr;
    delete _txt;

    std::cout << "SUCCESS" << std::endl;

    std::cout << "SECTION 2: CANVAS SUCCESSFUL" << std::endl
              << std::endl;

    //                                                              SECTION 3:PDF/PNG
    // =====================================================================================================================================================================
    std::cout << "SECTION 3: PDF/PNG" << std::endl;
    std::cout << "SECTION 3.1: EXPORT TO PDF" << std::endl;
    std::cout << "Attempting to export to PDF..." << std::endl;
    mspaint->PDFCanvas();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 3.2: EXPORT TO PNG" << std::endl;
    std::cout << "Attempting to export to PNG..." << std::endl;
    mspaint->PNGCanvas();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 3.3: ADDITIONAL TESTING" << std::endl;
    PNGExporter *temp_png = new PNGExporter(mspaint);
    temp_png->exportToFile();
    PDFExporter *temp_pdf = new PDFExporter(mspaint);
    temp_pdf->exportToFile();

    if (temp_pdf != nullptr)
    {
        delete temp_pdf;
    }

    if (temp_png != nullptr)
    {
        delete temp_png;
    }

    std::cout << "SECTION 3: PDF/PNG SUCCESSFUL" << std::endl;
    // =====================================================================================================================================================================

    delete square;
    delete squareFactory;
    delete sqr_clone;

    delete rec;
    delete recFactory;
    delete rec_clone;

    delete txt;
    delete txt_clone;
    delete txtboxFactory;

    delete mspaint;
    return 0;
}
