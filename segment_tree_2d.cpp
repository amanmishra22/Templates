class SegmentTree2D {
public:
    ll rows,cols;
    vector<vector<ll>> tree;
    vector<vector<ll>> matrix;
    ll comp(ll a,ll b){
        return a+b;
    }
    SegmentTree2D(vector<vector<ll>>& mat) {
        rows=mat.size();
        cols=mat[0].size();
        matrix=mat;
        tree.resize(4*rows+1,vector<ll>(4*cols+1,0));
        build_x(0,0,rows-1);
    }
    void build_x(ll vx,ll lx,ll rx) {
        if (lx!=rx) {
            ll mx=(lx+rx)/2;
            build_x(2*vx+1,lx,mx);
            build_x(2*vx+2,mx+1,rx);
        }
        build_y(vx,lx,rx,0,0,cols-1);
    }
    void build_y(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry) {
        if (ly==ry) {
            if (lx==rx) tree[vx][vy]=matrix[lx][ly];
            else tree[vx][vy]=comp(tree[2*vx+1][vy],tree[2*vx+2][vy]);
        } else {
            ll my=(ly+ry)/2;
            build_y(vx,lx,rx,2*vy+1,ly,my);
            build_y(vx,lx,rx,2*vy+2,my+1,ry);
            tree[vx][vy]=comp(tree[vx][2*vy+1],tree[vx][2*vy+2]);
        }
    }
    ll query_x(ll vx,ll lx,ll rx,ll qlx,ll qrx,ll qly,ll qry) {
        if (qlx>rx||qrx<lx) return 0;
        if (qlx<=lx&&rx<=qrx) return query_y(vx,0,0,cols-1,qly,qry); 
        ll mx=(lx+rx)/2;
        ll left_result=query_x(2*vx+1,lx,mx,qlx,qrx,qly,qry);
        ll right_result=query_x(2*vx+2,mx+1,rx,qlx,qrx,qly,qry);
        return comp(left_result,right_result);
    }
    ll query_y(ll vx,ll vy,ll ly,ll ry,ll qly,ll qry) {
        if (qly>ry||qry<ly) return 0;
        if (qly<=ly&&ry<=qry) return tree[vx][vy];
        ll my=(ly+ry)/2;
        ll left_result=query_y(vx,2*vy+1,ly,my,qly,qry);
        ll right_result=query_y(vx,2*vy+2,my+1,ry,qly,qry);
        return comp(left_result,right_result);
    }
    ll query(ll qlx,ll qrx,ll qly,ll qry) {
        return query_x(0,0,rows-1,qlx,qrx,qly,qry);  
    }
    void update_x(ll vx,ll lx,ll rx,ll px,ll py,ll new_val) {
        if (lx!=rx) {
            ll mx=(lx+rx)/2;
            if (px<=mx) update_x(2*vx+1,lx,mx,px,py,new_val);
            else update_x(2*vx+2,mx+1,rx,px,py,new_val);
        }
        update_y(vx,lx,rx,0,0,cols-1,px,py,new_val);
    }
    void update_y(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry,ll px,ll py,ll new_val) {
        if (ly==ry) {
            if (lx==rx) tree[vx][vy] ^= new_val;
            else tree[vx][vy]=comp(tree[2*vx+1][vy],tree[2*vx+2][vy]);
        } else {
            ll my=(ly+ry)/2;
            if (py<=my) update_y(vx,lx,rx,2*vy+1,ly,my,px,py,new_val);
            else update_y(vx,lx,rx,2*vy+2,my+1,ry,px,py,new_val);
            tree[vx][vy]=comp(tree[vx][2*vy+1],tree[vx][2*vy+2]);
        }
    }
    void update(ll px,ll py,ll new_val) {
        update_x(0,0,rows-1,px,py,new_val);
    }
};