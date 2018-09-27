%top{
    #include <fstream>
%}
%x dq
%x sq

%%
["]         { push_state(dq); out() << "&ldquo;"; }
[']         { push_state(sq); out() << "&lsquo;"; }
<dq>[^"']*  { out() << text(); }
<sq>[^']*   { out() << text(); }
<dq>["]     { out()<< "&rdquo;"; pop_state(); }
<dq>[']     { push_state(sq); out() << "&lsquo;"; }
<sq>[']     { pop_state(); out() << "&rsquo;"; }

%%

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        exit(1);
    }
    
    std::ifstream input_stream(argv[1], std::ios::binary);
    if (!input_stream.is_open()) {
        std::cerr << "Failed to open" << argv[1] << std::endl;
        exit(2);
    }
        
    Lexer(input_stream, std::cout ).lex();
}
