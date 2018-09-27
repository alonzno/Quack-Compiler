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
int main() { return Lexer().lex(); }
