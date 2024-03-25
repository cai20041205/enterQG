package como.gdut.jdbc;

import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CRUDUtils {
    private CRUDUtils() {
    }

    public static int update(String sql, Object... params) {
        Connection connection = JDBCUtils.getConnection();
        PreparedStatement preparedStatement = null;
        try {
            preparedStatement = connection.prepareStatement(sql);
            if (params != null) {
                for (int i = 0; i < params.length; i++) {
                    preparedStatement.setObject(i + 1, params[i]);
                }
            }
            int i = preparedStatement.executeUpdate();
            return i;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeAll(connection, null, preparedStatement);
        }
        return -1;
    }

    public static ArrayList<ArrayList> query(String sql, Object... params) {
        Connection connection = JDBCUtils.getConnection();
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            ArrayList<ArrayList> arrayLists=new ArrayList<>();
            preparedStatement = connection.prepareStatement(sql);

            if (params!=null) {
                for (int i = 0; i < params.length; i++) {
                    preparedStatement.setObject(i + 1, params[i]);
//                    System.out.println(params[i]);
                }
            }
            resultSet = preparedStatement.executeQuery();
            ResultSetMetaData metaData = resultSet.getMetaData();
            while (resultSet.next()) {
                ArrayList<Object> list=new ArrayList<>();
                for (int i = 0; i <metaData.getColumnCount() ; i++) {
//                    System.out.println(resultSet.getObject(i+1));
                    list.add(resultSet.getObject(i+1));
                }
                arrayLists.add(list);
            }
            return arrayLists;
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeAll(connection, resultSet, preparedStatement);
        }
        return null;
    }
}
